#include "Interface.h"
#include "choice.h"
#include "search.h"
#include <iostream>
#include "Initializer.h"

//-- Initialization ------------------
Interface* Interface::m_instance = nullptr;
Movie Interface::select;
bool Interface::pressed = false;
bool Interface::highBack = false;

Initializer* Interface::initializer = nullptr; //= new Initializer;


void Interface::update()
{
	Movie m;
	Search k;
	Choice d;
	graphics::MouseState ms;
	graphics::getMouseState(ms);



	int sx = graphics::windowToCanvasX(ms.cur_pos_x);
	int sy = graphics::windowToCanvasY(ms.cur_pos_y);


	if (MAIN_PAGE) { // if we are in the main page

		setHigh(contains(sx, sy)); // change the highlight of the search button accordingly

		if (highS && ms.button_left_pressed) {// if we preesed the search button
			
			graphics::playSound(std::string(ASSET_PATH) + "click.wav", 1, false);
			pressed = true;
			MAIN_PAGE = false;
			SEARCH_PAGE = true; // we go to the search page 
			

		}
	}
	else if (SEARCH_PAGE) { // if we are on the search page 

		setBack(containsB(sx, sy)); // change the highlight of the back button accordingly

		if (highBack && ms.button_left_pressed) {// we pressed the back button
			graphics::playSound(std::string(ASSET_PATH) + "click.wav", 1, false);
			
			SEARCH_PAGE = false;
			MAIN_PAGE = true;               // we go back to the main page 

			found = false;                             // we change them to their original state 
			k.setpressedD(false);
			k.setpressedE(false);
			k.setpressedY(false);
			k.setpressedT(false);
			k.setpressedG(false);
			type = 0;
			input = "";

		}
		k.update();
	}
	else if (CHOICE_PAGE) { // if we are in the choice page 
		
		setBack(containsB(sx, sy)); // change the highlight of the back button accordingly
		                           // we change them to their original state 
		k.setpressedD(false);
		k.setpressedE(false);
		k.setpressedY(false);
		k.setpressedT(false);
		k.setpressedG(false);
		


		if (highBack && ms.button_left_pressed) {// we pressed the back button
			graphics::playSound(std::string(ASSET_PATH) + "click.wav", 1, false);
			CHOICE_PAGE = false;
			SEARCH_PAGE = true;	// we go to the search page 		
			type = 0;
			input = "";
			found = false;

		}

		d.updatechoice();
	}
	else if (MOVIE_PAGE) {            // if we are on the movie page 
		setBack(containsB(sx, sy)); // change the highlight of the back button accordingly
		
		k.setpressedE(false);        // we return them to their original state
		input = "";
		k.setpressedD(false);
		k.setpressedY(false);
		k.setpressedT(false);
		k.setpressedG(false);
		type = 0;
		
		
		if (highBack && ms.button_left_pressed) {// we pressed the back button
			graphics::playSound(std::string(ASSET_PATH) + "click.wav", 1, false);
			MOVIE_PAGE = false;
			MAIN_PAGE = true;// we go to the main page 
			select = Movie(); // we re-initialize 
			found = false;
		}
		select.update();
	}
	else { // if all the variables are false then we have choosen a title and we need to find the object 
		
		findMovie();

	}

}

bool Interface::containsB(int x, int y) { 
	if (x >= 945 && x <= 1000) {
		if (y >= 0 && y <= 20) {
			return true;  // the mouse is into the "space" of the search box 
		}
	}
	return false;
}

bool Interface::contains(int x, int y) {

	if (x >= 305 && x <= 700) {
		if (y >= 200 && y <= 265) {
			return true;  // the mouse is into the "space" of the search box 
		}
	}
	return false;
}



void Interface::draw()
{
	Search k;
	Choice d;

	// we go to the appropriate draw 
	if (MAIN_PAGE) { 
		drawMain(highS);
	}
	else if (SEARCH_PAGE) {
		k.draw(highBack);
	}
	else if (CHOICE_PAGE) {
		d.drawchoice(highBack);
	}
	else if (MOVIE_PAGE) {
		if (!found) { //if there was no movie found
			drawNotfound(highBack);
		}
		else { //if there was a movie found, draw the movie page
			select.draw(highBack);
		}
	}


}

void Interface::init()
{// we create our movie objects 
 
	getInitializer()->prepareData();
		
}

Interface* Interface::getInstance()
{
	if (!m_instance) {
		m_instance = new Interface();
	}
	return m_instance;
}

Interface::Interface()
{
	
}

Interface::~Interface()
{
};

void Interface::findMovie() {


	for (Movie i :initializer->getMovieDAO().movie_list) { // for every movie object we have 
		//we transform inputs and titles in lower case so we can compare them
		std::string title = i.getTitle();
		transform(title.begin(), title.end(), title.begin(), ::tolower);

		std::string in = input;
		transform(in.begin(), in.end(), in.begin(), ::tolower);
		SEARCH_PAGE = false;
		MOVIE_PAGE = true;
		if (in == title && in != "") { // we found our movie (and it is not the empty movie)
			select = i; // we store the selected movie
			found = true; // we save that we found the movie 
		}


	}
	
}
Initializer* Interface::getInitializer()
{
	if (!initializer) {
		initializer = new Initializer();
	}
	return initializer;
}



