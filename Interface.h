#pragma once
#include "movie.h"
#include "widget.h"
#include "MovieDAO.h"
#include "Initializer.h"

class Interface :public Movie {
	static Interface* m_instance; // we only create one intreface instance
	static Initializer* initializer;

public:

	static Movie select; // the final selected movie
	
	Interface();

	bool highS = false; // it shows if the search button must be highlighted 
	static bool pressed; //its true if the search button was pressed
	static bool highBack; // it shows if the back button must be highlighted

	
	
	//Movie movies[N]; // we store all our movie objects
	
	// ------------------- we store each movie object in theie genre array ------------------
	//Movie Action[6];
	//Movie Thriller[3];
	//Movie Drama[6];
	//Movie Adventure[5];
	//Movie SciFi[2];
	//Movie Fantasy[3];
	//Movie War[1];
	//Movie Romance[1];
	//Movie Crime[4];
	//Movie Comedy[3];
	//Movie Family[2];
	//Movie Horror[1];
	//Movie Mystery[2];
	//----------------------------------------------------------------------------------
	void update();
	void draw();
	void init();


	void setHigh(bool h) { highS = h; } // we change the highlight of the search button
	void setBack(bool h) { highBack = h; }// we change the highlight of the back button

	bool containsB(int x, int y); // it returns if the mouse is over the back button
	bool contains(int x, int y);  // it returns if the mouse is over the search button
	
	static Interface* getInstance();// it the returns our unique interface instance
	static void releaseInstance() { if (m_instance) delete m_instance; m_instance = nullptr; }
	~Interface();
	
	void findMovie(); // we find the select movie and we save it on our widget::select 

	static Initializer* getInitializer();

};