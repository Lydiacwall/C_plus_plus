#include "widget.h"
#include <fstream>

//----- initialization of the static variables ---------------------------------
int const widget::titlex = 330;
int const widget::titley = 270;
bool widget::MAIN_PAGE = true;
bool widget::SEARCH_PAGE = false;
bool widget::CHOICE_PAGE = false;
bool widget::RESULT_PAGE = false;
bool widget::MOVIE_PAGE = false;
bool widget::found = false;
std::string widget::input = "";
int widget::type = 0; // 0=nothing pressed, 1=title box , 2=director box ,3=year 

//-------------------------- INTERFACE -----------------------------------------------------------
void widget::drawSearchBar(bool h) { // interface uses it

	graphics::Brush br;
	br.fill_color[0] = 0.84f;// gray color
	br.fill_color[1] = 0.84f;
	br.fill_color[2] = 0.84f;

	graphics::drawRect(500, 250, 400, 40, br);

	float a = 100 * h;

	br.outline_color[0] = a; // the outline of the box , it changes when the mouse is over the box
	br.outline_color[1] = a;
	br.outline_color[2] = a;

	graphics::drawRect(500, 250, 400, 40, br);

	graphics::setFont(std::string(ASSET_PATH) + "search.ttf");
	br.fill_color[0] = 0.0f;// black color
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;
	graphics::drawText(310, 260, 40, "Click here to start search ", br);

	graphics::resetPose();
}

void widget::drawMain(bool h)
{

	graphics::Brush br; 


	br.texture = std::string(ASSET_PATH) + "movies3.png"; // backround 

	graphics::drawRect(CANVAS_HEIGHT / 2, CANVAS_WIDTH / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);


	br.fill_color[0] = 0.96f; // red color letter
	br.fill_color[1] = 0.58f;
	br.fill_color[2] = 0.47f;

	graphics::setFont(std::string(ASSET_PATH) + "m2.ttf");// we set the font we want for the text

	graphics::drawText(200, 150, 100, "MovieBrowse", br);

	drawSearchBar(h); // we draw the button 

	//---------------- we show our names ------------------------------------------------------------
	graphics::setFont(std::string(ASSET_PATH) + "calibri.ttf");// we set the font we want for the text

	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;

	graphics::drawText(750, 470, 30, "WALLACE LYDIA", br);
	graphics::drawText(750, 490, 30, "KYRIAKOY IOANNA", br);
	graphics::resetPose();
}

void widget::drawBack(bool h) { //back button

	graphics::Brush br;
	br.fill_color[0] = 1.0f;// red color
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;

	graphics::drawRect(975, 20, 50, 40, br);

	float a = 100 * h;

	br.outline_color[0] = a; // the outline of the box , it changes when the mouse is over the box
	br.outline_color[1] = a;
	br.outline_color[2] = a;

	graphics::drawRect(975, 20, 50, 40, br);

	br.fill_color[0] = 0.0f;// black color
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;

	graphics::setFont(std::string(ASSET_PATH) + "calibri.ttf");

	br.texture = std::string(ASSET_PATH) + "return.png";
	graphics::drawRect(975, 20, 50, 40, br);

}

void widget::drawNotfound(bool back) { // Not Found page


	graphics::resetPose();
	graphics::Brush br;


	br.texture = std::string(ASSET_PATH) + "movieback.png"; // backround 
	graphics::drawRect(CANVAS_HEIGHT / 2, CANVAS_WIDTH / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
	graphics::setWindowBackground(br);

	br.fill_color[0] = 0.96f;// red color letter
	br.fill_color[1] = 0.58f;
	br.fill_color[2] = 0.47f;

	graphics::setFont(std::string(ASSET_PATH) + "m2.ttf");// we set the font we want for the text

	graphics::drawText(100, 150, 40, "Sorry.We did not find what you were looking for ", br);

	graphics::drawText(200, 250, 50, "Try searching again", br);

	drawBack(back);                       // we draw the back button
}

//----------------------------- MOVIE -------------------------------------------------------------
void widget::drawPicture(int id) {


	graphics::Brush br;
	br.outline_color[0] = 0.0f;
	br.outline_color[1] = 0.0f;
	br.outline_color[2] = 0.0f;

	br.texture = std::string(ASSET_PATH) + std::to_string(id) + ".png"; //we select the picture that its name its the same with our selected movie
	graphics::drawRect(200,226,400,450, br);

}

void widget::drawTitle(std::string title) {

	graphics::Brush br;
	br.fill_color[0] = 1.0f;// white color
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;

	graphics::setFont(std::string(ASSET_PATH) + "title.otf");// we set the font we want for the text

	graphics::drawText(500, 70, 50, title, br);


}

void widget::drawGenre(int id) {

	int l = 0;            //we count how many genres we have
	std::string genre[3]; // we have max 3 genres per movie 
	bool flag = true;     // our flag that shows if we have not found our movie
	int xr = 55;          // we will use it to move our genre box 
	int xt = 15;          // we will use it to move our text

	std::fstream newfile;
	newfile.open(std::string(ASSET_PATH) + "movies_genre.txt", std::ios::in); //open the file 
	if (newfile.is_open()) {                                                  //checking whether the file is open
		std::string tp;


		while (flag == true) {                                               //while we have not found our movie id
			getline(newfile, tp);
			if (tp == std::to_string(id)) {                                   //we found our movie (to_string-> from int to string)
				getline(newfile, tp);                                         // we take the next line so we do not save the id 
				while (tp != "") {                                            // while have not reached the end of the genres
					genre[l] = tp;                                            //we save the genre
					l = l + 1;                                                // we increase the counter
					getline(newfile, tp);                                     // we take the next line

				}
				if (tp == "") {                                                 // if we went in the while 
					flag = false;                                               //we found the movie
				}

			}

		}

		newfile.close(); //close the file 
	}


	for (int i = 0; i < l; i++) { // for every genre

		graphics::Brush br;
		br.fill_color[0] = 0.58f;// gray color
		br.fill_color[1] = 0.58f;
		br.fill_color[2] = 0.58f;

		br.outline_color[0] = 0.00f;//black color 
		br.outline_color[1] = 0.00f;
		br.outline_color[2] = 0.00f;

		graphics::drawRect(xr, 475, 100, 30, br);


		br.fill_color[0] = 0.00f;//black color
		br.fill_color[1] = 0.00f;
		br.fill_color[2] = 0.00;

		graphics::setFont(std::string(ASSET_PATH) + "calibri.ttf");
		graphics::drawText(xt, 480, 20, genre[i], br);

		xt = xt + 112; // we move the x for the next text 
		xr = xr + 115;// we move the x for the next box 
	}


}

void widget::drawSummary(int id) {

	graphics::Brush br;
	br.fill_color[0] = 1.0f; // white color
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;

	graphics::setFont(std::string(ASSET_PATH) + "title.otf");// we set the font we want for the text

	graphics::drawText(500, 150, 25, "SUMMARY:", br);
	graphics::setFont(std::string(ASSET_PATH) + "calibri.ttf");// we set the font we want for the text
	
	
	int y = 175; //the position of our letters
	bool flag = true;

	
	std::fstream newfile; 
	newfile.open(std::string(ASSET_PATH) + "movie_info.txt", std::ios::in); //open the file 
	if (newfile.is_open()) {                     //checking whether the file is open
		
		std::string tp;                          // we save here the line we get from our file each time

		while (flag == true) {                   // flag = true means that we have not found our movie id 
			getline(newfile, tp);                // we take the first line 

			if (tp == std::to_string(id)) {      //(to_string-> from int to string)   we found our movie 
				getline(newfile, tp);            // we take the next line so we do not show the id 
				while (tp != "") {               // until we reach the end

					graphics::drawText(500, y, 20, tp, br); // we show it 
					y = y + 25;                             //we move the letter height down 
					getline(newfile, tp);                   // we take the next line 

				}
				if (tp == "") {                            // if we went in the while  and we found our movie 
					flag = false;                          //we found our movie
				}

			}

		}

		newfile.close(); //close the file .
	}





}

void widget::drawDirector(std::string director) {

	graphics::Brush br;
	br.fill_color[0] = 1.0f;// white color
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;

	graphics::setFont(std::string(ASSET_PATH) + "title.otf");// we set the font we want for the text


	graphics::drawText(500, 380, 25, "DIRECTOR:", br);
	graphics::setFont(std::string(ASSET_PATH) + "calibri.ttf");
	graphics::drawText(650, 380, 20, director, br);






}

void widget::drawYear(int year) {

	graphics::Brush br;
	br.fill_color[0] = 1.0f;// white color
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;

	graphics::setFont(std::string(ASSET_PATH) + "title.otf");// we set the font we want for the text


	graphics::drawText(800, 380, 25, "YEAR:", br);
	graphics::setFont(std::string(ASSET_PATH) + "calibri.ttf");
	graphics::drawText(910, 380, 20, std::to_string(year), br);





}

void widget::drawProd(int id) {

	graphics::Brush br;
	br.fill_color[0] = 1.0f;// white color
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;

	graphics::setFont(std::string(ASSET_PATH) + "title.otf");// we set the font we want for the text

	graphics::drawText(500, 420, 25, "STARS:", br);

	bool flag = true;

	graphics::setFont(std::string(ASSET_PATH) + "calibri.ttf");// we set the font we want for the text
	std::fstream newfile;
	newfile.open(std::string(ASSET_PATH) + "prod.txt", std::ios::in);
	if (newfile.is_open()) {                                     //checking whether the file is open
		std::string tp;


		while (flag == true) {                                   // flag = true means that we have not found our movie id 
			getline(newfile, tp);                                // we take the first line 

			if (tp == std::to_string(id)) {                     //(to_string-> from int to string)  we found our movie 
				getline(newfile, tp);                           // we take the next line so we do not show the id 
				while (tp != "") {                              // until we reach the end

					graphics::drawText(600, 420, 20, tp, br);  // we show it 

					getline(newfile, tp);                      // we take the next line 

				}
				if (tp == "") {                                 // if we went in the while  and we found our movie 
					flag = false;                               //we showed all our genres
				}

			}

		}

		newfile.close();                                         //close the file.
	}




}





// ----------------------------- SEARCH ------------------------------------------------------------
void widget::drawSearch()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "movies3.png"; // backround 

	graphics::drawRect(CANVAS_HEIGHT / 2, CANVAS_WIDTH / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);


	br.fill_color[0] = 0.96f;// red color letter
	br.fill_color[1] = 0.58f;
	br.fill_color[2] = 0.47f;

	graphics::setFont(std::string(ASSET_PATH) + "m2.ttf");// we set the font we want for the text

	graphics::drawText(200, 150, 100, "MovieBrowse", br);


	br.fill_color[0] = 1.0f;// gray color
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;


	br.fill_opacity = 0.5f;

	br.outline_color[0] = 0.0f;
	br.outline_color[1] = 0.0f;
	br.outline_color[2] = 0.0f;

	graphics::setFont("");
	br.texture = "";
	graphics::drawRect(500, 355, 900, 250, br);

	graphics::setFont(std::string(ASSET_PATH) + "title.otf");// we set the font we want for the text

	br.fill_opacity = 1.0f;
	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;

	graphics::drawText(420, 210, 40, "SEARCH", br);


}

void widget::drawSTitle(bool h)
{

	graphics::Brush br;

	br.fill_color[0] = 0.33f;
	br.fill_color[1] = 0.33f;
	br.fill_color[2] = 0.33f;

	graphics::drawRect(500, 260, 350, 30, br);

	float a = 100 * h;

	br.outline_color[0] = a;   // the outline of the box , it changes when the mouse is over the box
	br.outline_color[1] = a;
	br.outline_color[2] = a;



	graphics::drawRect(500, 260, 350, 30, br);


	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;

	graphics::setFont(std::string(ASSET_PATH) + "title.otf");// we set the font we want for the text
	graphics::drawText(65, 270, 30, "BY TITLE:", br);



}

void widget::drawSDirector(bool h) {
	graphics::Brush br;

	br.fill_color[0] = 0.33f;
	br.fill_color[1] = 0.33f;
	br.fill_color[2] = 0.33f;

	graphics::drawRect(500, 310, 350, 30, br);


	float a = 100 * h;

	br.outline_color[0] = a; // the outline of the box , it changes when the mouse is over the box
	br.outline_color[1] = a;
	br.outline_color[2] = a;

	graphics::drawRect(500, 310, 350, 30, br);

	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;

	graphics::setFont(std::string(ASSET_PATH) + "title.otf");// we set the font we want for the text
	graphics::drawText(65, 320, 30, "BY DIRECTOR:", br);







}

void widget::drawSYear(bool h) {

	graphics::Brush br;

	br.fill_color[0] = 0.33f;
	br.fill_color[1] = 0.33f;
	br.fill_color[2] = 0.33f;

	graphics::drawRect(500, 360, 350, 30, br);

	float a = 100 * h;

	br.outline_color[0] = a; // the outline of the box , it changes when the mouse is over the box
	br.outline_color[1] = a;
	br.outline_color[2] = a;

	graphics::drawRect(500, 360, 350, 30, br);


	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;

	graphics::setFont(std::string(ASSET_PATH) + "title.otf");// we set the font we want for the text
	graphics::drawText(65, 370, 30, "BY YEAR:", br);







}

void widget::drawSGenre(bool h) {
	graphics::Brush br;

	br.fill_color[0] = 0.33f;
	br.fill_color[1] = 0.33f;
	br.fill_color[2] = 0.33f;

	graphics::drawRect(500, 410 , 350, 30, br);

	float a = 100 * h;

	br.outline_color[0] = a;  // the outline of the box , it changes when the mouse is over the box
	br.outline_color[1] = a;
	br.outline_color[2] = a;

	graphics::drawRect(500,410, 350, 30, br);


	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;

	graphics::setFont(std::string(ASSET_PATH) + "title.otf");// we set the font we want for the text
	graphics::drawText(65, 420, 30, "BY GENRE:", br);

	graphics::setFont(std::string(ASSET_PATH) + "calibri.ttf");
	graphics::drawText(65, 460, 20, "When you are done typping please press enter to start the search",br);


}

void widget::drawText(int x, int y, std::string text) {

	graphics::Brush br;

	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;

	graphics::setFont(std::string(ASSET_PATH) + "calibri.ttf");
	graphics::drawText(x, y, 25, text, br);
}

void widget::drawList() {
	std::string genres[13] = { "Action","Thriller","Drama","Adventure","SciFi","Fantasy","War","Romance","Crime","Comedy","Family","Horror","Mystery" };

	graphics::Brush br;


	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 0.0f;
	br.fill_color[2] = 0.0f;

	graphics::setFont(std::string(ASSET_PATH) + "calibri.ttf");
	graphics::drawText(750, 245, 20, "Available Gerne", br);
	int y = 265;
	int k = 0;
	int y2 = 265;
	for (std::string i : genres) {
		if (k > 6) {
			graphics::drawText(850, y2, 20, i, br);
			y2 = y2 + 20;
		}
		else {
			graphics::drawText(700, y, 20, i, br);
			y = y + 20;
		}
		k++;
	}






}



//--------------------------- CHOICE -------------------------------------------------------------

void widget::drawChoice(std::string title) {
	
	graphics::resetPose();
	graphics::Brush br;

	br.texture = std::string(ASSET_PATH) + "movies3.png"; // backround 
	
	graphics::drawRect(CANVAS_HEIGHT / 2, CANVAS_WIDTH / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
	



	br.fill_color[0] = 1.0f;// white color
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 1.0f;

	br.fill_opacity = 0.5f;
	
	graphics::setFont("");
	br.texture = "";
	
	br.outline_color[0] = 0.0f;
	br.outline_color[1] = 0.0f;
	br.outline_color[2] = 0.0f;


	graphics::drawRect(500, 250, 900,450, br);

	graphics::Brush br2;
	br2.fill_color[0] = 1.0f;// white color
	br2.fill_color[1] = 1.0f;
	br2.fill_color[2] = 1.0f;

	br2.outline_color[0] = 0.0f;
	br2.outline_color[1] = 0.0f;
	br2.outline_color[2] = 0.0f;

	graphics::setFont(std::string(ASSET_PATH) + "title.otf");// we set the font we want for the text
	
	// we see what type of search we have 
	if (type == 2) {
		graphics::drawText(60, 100, 50, "Movies made by the director " + title, br2);
	}
	else if (type == 3) {
		graphics::drawText(60, 100, 50, "Movies made in the year " + title, br2);
	}
	else if (type == 4) {
		graphics::drawText(60, 100, 50, "Movies with the"+ title +" genre" , br2);
	}

	graphics::Brush br3;
	br3.fill_color[0] = 0.0f;// black color
	br3.fill_color[1] = 0.0f;
	br3.fill_color[2] = 0.0f;

	graphics::drawText(60, 140, 30, "Press button to choose your movie", br3);


}




