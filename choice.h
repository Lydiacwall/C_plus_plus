#pragma once
#include "widget.h"
#include "Interface.h"


class Choice :public Interface {

public:
	static Movie list[N]; // we store the movie objects that confirm the choosen type of search (like if year =1999 , list contains all the movies with that year
	static int count; // we count how many movies confirm the choosen type of search
	static bool S;   // shows if any box is pressed
	Movie movie;     // we use it to temporary store a movie object 

	void drawchoice(bool back); // it takes the boolean back variable that shows if the back button must be highlighted 
	void updatechoice();

	void setHigh(bool h) {S = h;} // it changes the state of the S 
	int containstxt(int x, int y, int count); // it returns in which box the mouse is "on" . If none returns 100

	Choice();

	int drawResults(std::string title); // it finds the movies with the choosen genre and it returns how many 
};