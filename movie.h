#pragma once
#include "widget.h"
#include <array>

class Movie : public widget {
protected:

	int year = 0;
	std::string director;
	static int k; // every movie will have a id , for easier access to files
	int id = 0;
	std::array<std::string, 3> genre_list;


public:
	std::string title;
	void draw(bool back);
	void update();
	Movie();
	~Movie();
	Movie(std::string title, int year, std::string director);

	std::string getTitle();
	void setTitle(std::string title);

	static int flag;

	std::string getDirector();
	void setDirector(std::string director = " ");

	int getYear();
	void setYear(int year = 0);

	std::array<std::string , 3> getGenre();
	void addGenre(std::string genre);

	int getId();
	void startM();


	//~Movie();



};