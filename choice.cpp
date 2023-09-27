#include "choice.h"
#include <iostream>
#include "Initializer.h"


int Choice::count = 0; //counts number of movies found with the same director/year
Movie Choice::list[N];
bool Choice::S = false;

void Choice::drawchoice( bool back)
{
	std::string Igenres; // we save the lowercase input 
	std::string genres[13] = { "Action","Thriller","Drama","Adventure","SciFi","Fantasy","War","Romance","Crime","Comedy","Family","Horror","Mystery" };
	std::string title; //title will be assigned the director or year that is given by the user
	std::string choice[N]; //save all movie titles with the same director/year as the given one in the choice list
	
	Interface* inte = Interface::getInstance();
	Initializer* init = Interface::getInitializer();

	for (int i = 0; i < N; i++) 
	{ // for every movie we have 
		
		Movie m = init->getMovieDAO().movie_list[i];

		if (type == 2) { // we choose search by director
			
			std::string director = m.getDirector(); // we take the director of the current obj
			transform(director.begin(), director.end(), director.begin(), ::tolower); // we make it to lowercase
			
			std::string in = input;// we take the input 
			title = in;  // we save it so we can later show it 
			transform(in.begin(), in.end(), in.begin(), ::tolower);// we make to lowercase
			
			if (in == director) { // we found our director
				choice[i] = m.getTitle(); // we save the title of the movie 
				found = true;   // we at least found one movie that maches the search 
			}
			else {
				choice[i] = "none"; //for all the other movies that don't have the same director as the given one, save "none"
			}
		}
		else if (type == 3) { // we choosen search by year 
			
			int year = m.getYear();// we take the year of the current obj
			std::string in = input;
			title = in;// we save it so we can use it later
			
			if (in == std::to_string(year)) { // we found our year
				choice[i] = m.getTitle(); // we save the title of the movie 
				found = true; // we at least found one movie that maches the search
			}
			else {
				choice[i] = "none";  //for all the other movies that don't have the same director as the given one, save "none"
			}

		}
		else if (type == 4) {// we choosen search by genre
			
			Igenres = input;// we save the imput 
			title = input; // we save it so we can show it later 
			transform(Igenres.begin(),Igenres.end(), Igenres.begin(), ::tolower);// we make it to lowercase
			
			for (std::string i : genres) { // for every genre we have 
				transform(i.begin(),i.end(),i.begin(), ::tolower);
				if (Igenres == i) {
					found = true;// we have the genre that was choosen
					
				}
			}

		}

	}

	if (!found) { //if there was no movie found, draw the Not Found page
		drawNotfound(back);
	}
	else { //draw choice page
		
		drawChoice(Igenres);
		drawBack(back);
		
		graphics::Brush br;
		br.fill_color[0] = 0.0f;// black color
		br.fill_color[1] = 0.0f;
		br.fill_color[2] = 0.0f;
		
		int posx = 60;
		int posy = 200;

		if (type == 2 || type == 3) {
			
			for (int i = 0; i < N; i++) {
				if (choice[i] != "none") {
					graphics::drawText(posx, posy, 30, choice[i], br);
					graphics::drawRect(500, posy - 10, 30, 30, br);
					posy = posy + 40;
					list[count] = init->getMovieDAO().movie_list[i]; //save movies with the same director/year in the movie list
					count = count + 1; // increase number of movies found with the same director / year
				}
			}
		}
		else if (type == 4) {
			count = drawResults(title);

		}
		
	}


}

int Choice:: drawResults(std::string title) {
	int posx = 60;
	int posy = 200;
	int count = 0;

	Interface* inte = Interface::getInstance();
	Initializer* init = Interface::getInitializer();
     
	graphics::Brush br;
	br.fill_color[0] = 0.0f;// black color
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;
	
	// we find which genre was choosen, we save the movies in the list[] and then we return the count 
	transform(title.begin(), title.end(), title.begin(), ::tolower);
		int k = 0;
		std::array<Movie,6> list;
		list = init->getMovieDAO().findByGenre(title);

		for (Movie i : list) {
			graphics::drawText(posx, posy, 30,i.getTitle(), br);
			graphics::drawRect(500, posy - 10, 30, 30, br);
			posy = posy + 40;
			//list[k] = i;
			count++;
			k = k + 1;
		}
		

	return count;
}

void Choice::updatechoice()
{

	graphics::MouseState ms;
	graphics::getMouseState(ms);

	//get position of mouse:
	int sx = graphics::windowToCanvasX(ms.cur_pos_x);
	int sy = graphics::windowToCanvasY(ms.cur_pos_y);
	
	int posy = 80; // posy = 80px is the distance between each movie button in pixels

	int a = containstxt(sx, sy, count); // int a : keeps the number of the movie whose button is on the bottom of the mouse
	
	if (a != 100) { // we are over one of the boxes
		S = true;
	}


	if (S && ms.button_left_pressed) { //if button is pressed, select movie from list
		graphics::playSound(std::string(ASSET_PATH) + "click.wav", 1, false);
		if (a != 100) {
			select = list[a];//we save the movie 
		}
		CHOICE_PAGE = false;
		MOVIE_PAGE = true;//we go to the movie page 
		input = select.getTitle(); // we save on the input the title of the movie 
	}

	count = 0; //reinitialize movie counter

}


Choice::Choice() {

}



int Choice::containstxt(int x, int y, int count) { // it shows if the mouse is over any box 
	int num = 100;
	int posy = 40;
	for (int i = 0; i < count; i++) {
		if (x >= 485 && x <= 515) {
			if (y >= 175 + i * posy && y <= 205 + i * posy) {
				num = i;
				return num;  // the mouse is into the "space" of the white box 
			}
		}
	}
	return num;
}




