#pragma once
#include "graphics.h"
#include "config.h"
#include "widget.h"
#include <iostream>
#include "scancodes.h"
#include"graphics.h"
#include "Interface.h"
#include "movie.h" 


class Search:public widget {
	static bool th; //to highlight the title box
	static bool dh; //to highlight the director box
	static bool yh; //to highlight the year box
	static bool gh;//to highlight the genre box

	static bool pressedT; // if we pressed the title box
	static bool pressedE; // if we pressed enter , it shows the end of the search 
	static bool pressedD;// if we pressed the director box
	static bool pressedY;// if we pressed the year box
	static bool pressedG;// if we pressed the gerne box

	static float timer; // a timer so we cannot type so fast and the computer does not catch it 
	static int flag;    // it a even number if the caps lock its off, and a not even number when the caps lock is on
	static bool temp;   // it is true if we have selected the caps lock , even one time . So when flag=0 it does not activate the caps lock
	

public:
	void draw(bool a); // it takes the state of the outline of the back button 
	void update();
	Search();

    bool containsT(int x, int y); // it returns true if the mouse is in the title box. It takes the position of the mouse 
	bool containsD(int x, int y); // it returns true if the mouse is in the director box . It takes the position of the mouse 
	bool containsY(int x, int y); // it returns true if the mouse is in the year box .It takes the position of the mouse 
	bool containsG(int x, int y); // it returns true if the mouse is in the genre box .It takes the position of the mouse 

	// --------------------- setters for the highlight of the boxes 
	void setHighT(bool h) { th = h; }// it changes the highlight of the title box .
	void setHighD(bool h) { dh = h; }// it changes the highlight of the director box
	void setHighY(bool h) { yh = h; }// it changes the highlight of the year box
	void setHighG(bool h) { gh = h; }// it changes the highlight of the genre box

	// ----- setters for our buttons ----------------------------
	void setpressedT(bool a) { pressedT = a; }
	void setpressedD(bool a) { pressedD = a; }
	void setpressedE(bool a) { pressedE = a; }
	void setpressedY(bool a) { pressedY = a; }
	void setpressedG(bool a) { pressedG = a; }
	







};
