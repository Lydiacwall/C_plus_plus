#include "search.h"
#include <iostream>
#include "scancodes.h"
#include "graphics.h"
#include "string.h"
#include <cstdlib>
#include <exception>

// we initialize our variables
bool Search::th = false;
bool Search::dh = false;
bool Search::yh = false;
bool Search::gh = false;

bool Search::pressedE = false;
bool Search::pressedT = false;
bool Search::pressedD = false;
bool Search::pressedG = false;
bool Search::pressedY = false;

float Search::timer = 0.0;
int Search::flag = 0;
bool Search::temp = false;

void Search::draw(bool a) 
{
	graphics::resetPose();
	graphics::Brush br;

	drawSearch();
	drawSTitle(th);
	drawSDirector(dh);
	drawSYear(yh);
	drawSGenre(gh);
	drawBack(a);

	// we show the input in the correct position 
	if (pressedT) {
		drawText(titlex, titley, input);
	}
	else if (pressedD) {
		drawText(titlex, titley + 50, input);

	}
	else if (pressedY) {
		drawText(titlex, titley + 100, input);

	}
	else if (pressedG) {
		drawList();
		drawText(titlex, titley + 150, input);

	}



}


void Search::update()
{
	
	graphics::MouseState ms;
	graphics::getMouseState(ms);
	// we take the cordinates of the mouse
	float sx = graphics::windowToCanvasX(ms.cur_pos_x);
	float sy = graphics::windowToCanvasY(ms.cur_pos_y);

	
	
	// so the outline of the boxes can change when we have not selected something , and it stays highlighted when we have choosen something
	if (!pressedT && type==0) { // if we have not pressed any box then it should change the highlight
		setHighT(containsT(sx, sy));//highlight
	}
	if (!pressedD && type==0) {
		setHighD(containsD(sx, sy));
	}
	if (!pressedY && type==0) {
		setHighY(containsY(sx, sy));
	}
	if (!pressedG && type == 0) {
		setHighG(containsG(sx, sy));
	}

	 //---------------------- WE UN-CHOOSE A SEARCH TYPE ---------------------
	 if (pressedT && th && ms.button_left_pressed) {// we pressed again in the box 
		 pressedT = false;
		 setHighT(false);
		 type = 0;
		 input = "";// we start again from the beggining 
		 graphics::playSound(std::string(ASSET_PATH) + "click.wav", 1, false);
	 }
	 if (pressedD && dh && ms.button_left_pressed) {// we pressed again in the box 
		 pressedD = false;
		 setHighD(false);
		 type = 0;
		 input = "";// we start again from the beggining 
		 graphics::playSound(std::string(ASSET_PATH) + "click.wav", 1, false);
	 }
	 if (pressedY && yh && ms.button_left_pressed) {// we pressed again in the box 
		 pressedY = false;
		 setHighY(false);
		 type = 0;
		 input = "";// we start again from the beggining 
		 graphics::playSound(std::string(ASSET_PATH) + "click.wav", 1, false);
	 }
	 if (pressedG && gh && ms.button_left_pressed) {
		 pressedG = false;
		 setHighG(false);
		 type = 0;
		 input = "";// we start again from the beggining 
		 graphics::playSound(std::string(ASSET_PATH) + "click.wav", 1, false);

	 }

//-------------------------- we start searching -------------------------------------	

	if (th && ms.button_left_pressed) { // we pressed search by title
		pressedT = true;
		type = 1;
		graphics::playSound(std::string(ASSET_PATH) + "click.wav", 1, false);
	}
	
	if (dh && ms.button_left_pressed) { // we pressed search by director 
		pressedD = true;
		type = 2;
		graphics::playSound(std::string(ASSET_PATH) + "click.wav", 1, false);
	}
	if (yh && ms.button_left_pressed) { // we pressed search by year
		pressedY = true;
		type = 3;
		graphics::playSound(std::string(ASSET_PATH) + "click.wav", 1, false);
	}
	if (gh && ms.button_left_pressed) { // we pressed search by genre
		pressedG = true;
		type = 4;
		graphics::playSound(std::string(ASSET_PATH) + "click.wav", 1, false);
	}
 
	
    
	if (type != 0 && (!pressedE)) { // if we have pressed any button and not the enter button yet
		
		float delta = graphics::getDeltaTime();
		timer = timer + delta;

		
		// we have two character arrays in case we have the caps lock on 
		char button[] = "abcdefghijklmnopqrstuvwxyz0123456789"; 
		char BUTTON[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		
		//we see if any button was pushed , and which one 
		bool a = graphics::getKeyState(graphics::SCANCODE_A);
		bool b = graphics::getKeyState(graphics::SCANCODE_B);
		bool c = graphics::getKeyState(graphics::SCANCODE_C);
		bool d = graphics::getKeyState(graphics::SCANCODE_D);
		bool e = graphics::getKeyState(graphics::SCANCODE_E);
		bool f = graphics::getKeyState(graphics::SCANCODE_F);
		bool g = graphics::getKeyState(graphics::SCANCODE_G);
		bool h = graphics::getKeyState(graphics::SCANCODE_H);
		bool i = graphics::getKeyState(graphics::SCANCODE_I);
		bool j = graphics::getKeyState(graphics::SCANCODE_J);
		bool k = graphics::getKeyState(graphics::SCANCODE_K);
		bool l = graphics::getKeyState(graphics::SCANCODE_L);
		bool m = graphics::getKeyState(graphics::SCANCODE_M);
		bool n = graphics::getKeyState(graphics::SCANCODE_N);
		bool o = graphics::getKeyState(graphics::SCANCODE_O);
		bool p = graphics::getKeyState(graphics::SCANCODE_P);
		bool q = graphics::getKeyState(graphics::SCANCODE_Q);
		bool r = graphics::getKeyState(graphics::SCANCODE_R);
		bool s = graphics::getKeyState(graphics::SCANCODE_S);
		bool t = graphics::getKeyState(graphics::SCANCODE_T);
		bool u = graphics::getKeyState(graphics::SCANCODE_U);
		bool v = graphics::getKeyState(graphics::SCANCODE_V);
		bool w = graphics::getKeyState(graphics::SCANCODE_W);
		bool x = graphics::getKeyState(graphics::SCANCODE_X);
		bool y = graphics::getKeyState(graphics::SCANCODE_Y);
		bool z = graphics::getKeyState(graphics::SCANCODE_Z);

		bool zero = graphics::getKeyState(graphics::SCANCODE_0);
		bool one = graphics::getKeyState(graphics::SCANCODE_1);
		bool two = graphics::getKeyState(graphics::SCANCODE_2);
		bool three = graphics::getKeyState(graphics::SCANCODE_3);
		bool four = graphics::getKeyState(graphics::SCANCODE_4);
		bool five = graphics::getKeyState(graphics::SCANCODE_5);
		bool six = graphics::getKeyState(graphics::SCANCODE_6);
		bool seven = graphics::getKeyState(graphics::SCANCODE_7);
		bool eight = graphics::getKeyState(graphics::SCANCODE_8);
		bool nine = graphics::getKeyState(graphics::SCANCODE_9);

		bool capslk = graphics::getKeyState(graphics::SCANCODE_CAPSLOCK);
		bool back = graphics::getKeyState(graphics::SCANCODE_BACKSPACE);
		bool space = graphics::getKeyState(graphics::SCANCODE_SPACE);
		bool enter = graphics::getKeyState(graphics::SCANCODE_RETURN);

		bool symbol[] = { a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p,
						 q, r, s, t, u, v, w, x, y, z, zero, one, two, three,
						  four, five, six, seven, eight, nine };

		if (capslk) { // we pressed the caps lock , is it to turn it off or on;
			temp = true;  // we figure this out with temp and flag 
			flag = flag + 1;
			
		}
		for (int i = 0; i < 36; i++) { // for every character we have 
			if (timer > 150) {         // when we allow the next input
				if (symbol[i]) {
					if (temp && flag % 2 == 1) { // if the caps lock its on and 
						
						input = input + BUTTON[i];
					}

					else { // caps lock are off
						input = input + button[i];
					}
					timer = 0; //resetting timer
				}
				// special inputs
				else if (space) {
					input = input + " ";
					timer = 0;
				}
				else if (back) {
					try {
						input.erase(input.size() - 1); // we erase the char in the last position 
						timer = 0;
						
					}
					catch(std::out_of_range){ // if we erase an empty input
						input = "";

					}
				}
				else if (enter) {// if we presses enter , the typping stops 
					pressedE = true;
				}
			}
		}
	}	
	else if (pressedE) {// pressed enter 
		
		SEARCH_PAGE = false;
		if (type == 2 || type == 3 || type == 4) { // if we have not selected a specific movie we go to the choice page 
			CHOICE_PAGE = true;
		}
		// if we have selected search by title(type=1) , then we go directly to show the  movie 
		
	}

}

Search::Search()
{
}

bool Search::containsT(int x, int y) // if the mouse is within the coordinates of the title box 
{
	if (x >= 325 && x <= 673) {
		if (y >= 243 && y <= 274) {
			return true;
		}
	}
	return false;
}

bool Search::containsD(int x, int y) { // if the mouse is within the coordinates of the director box 

	if (x >= 324 && x <= 673) {
		if (y >= 294 && y <= 322) {
			return true;
		}
	}
	return false;
} 

bool Search::containsY(int x,int y) { // if the mouse is within the coordinates of the year box

	if (x >= 325 && x <= 673) {
		if (y >= 345 && y <= 374) {
			return true;
		}
	}
	return false;
}

bool Search::containsG(int x, int y) { // if the mouse is within the coordinates of the genre box

	if (x >= 325 && x <= 673) {
		if (y >= 395 && y <= 425) {
			return true;
		}
	}
	return false;

}











