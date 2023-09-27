#pragma once
#include <string>
#include <algorithm>
#include "graphics.h"
#include "config.h"

class widget {

public:
	// boolean variables that shows in what page we are 
	static bool MAIN_PAGE; 
	static bool SEARCH_PAGE;
	static bool RESULT_PAGE;
	static bool CHOICE_PAGE;
	static bool MOVIE_PAGE;
//----------------------------------------------------------	
	static bool found;        // its true if we found the movie that we are searching for  
	
	static const int titlex;  // const variable the shows the position x of the title box in the search page
	static const int titley;  // const variable the shows the position y of the title box in the search page
	
	static std::string input; // the input 
	static int type;          // what type of search we have (1 = by title , 2 = by director , 3 = by year , 4 = by genre ) 
	static bool temp;         //it shows if the caps lock are in use 

	// ---------------------- MOVIE -------------------------------
	void drawPicture(int id);                  // it draws the picture of the choosen movie. It takes the movie id.
	void drawTitle(std::string title);         // it draws the title of the choosen movie. It takes the title of the movie.
	void drawGenre(int id);                    // it draws the genre of the choosen movie. It takes the movie id. 
	void drawSummary(int id);                  // it draws the summary of the choosen movie. It takes the movie id. 
	void drawDirector(std::string director);   // it draws the director of the choosen movie. It takes the name of the director.
	void drawProd(int id);                     // it draws the protagonists of the choosen movie . It takes the movie id.
	void drawYear(int year);                   // it draws the year of the choosen movie . It takes the year the movie was made.
	
	//------------------------- INTERFACE ------------------------------------
	void drawMain(bool h);       //it draws the main page.It takes a boolean  variable that shows if the outline of the search button must be highlighted                             
	void drawSearchBar(bool h);  // it draws the search button.It takes a boolean variable that shows if the outline of the search button must be highlighted
	void drawBack(bool h);       // it draws the back button .It takes a boolean  variable that shows if the outline of the back button must be highlighted
	void drawNotfound(bool back); // it draws the page when we did not find what the uses typed. It takes the boolean back variable that shows
	                              // if the outline must be highlighted
	//--------------------------- SEARCH--------------------------------
	void drawSearch();                              // it draws the backround and the space  of the search page 
	void drawSTitle(bool h);                        // it draws the title box.It takes a boolean variable that shows if the outline of the button must be highlighted
	void drawSDirector(bool h);                     // it draws the director box .It takes a boolean variable that shows if the outline of the button must be highlighted
	void drawSYear(bool h);                         // it draws the year box .It takes a boolean variable that shows if the outline of the button must be highlighted
	void drawSGenre(bool h);                        // it draws the genre box .It takes a boolean variable that shows if the outline of the button must be highlighted
	void drawText(int x, int y, std::string text);  // it shows the input. It takes the position x, y that the imput must be shown and the input.
	void drawList();                                // it shows the available genre

	//------------------------ CHOICE ------------------------------------ 
	void drawChoice(std::string title);            // it draws the backround of the choice page. It takes a string variable that :
};                                                 // if type=2 has the selected director, if type=3 has the  selected year and if type=4 has the selected genre

