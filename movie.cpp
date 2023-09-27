#include "movie.h"


int Movie::k = 0;// initialization of a static member must be outside of the class
int Movie::flag = 0;

void Movie::draw(bool back)
{

	graphics::resetPose();
	graphics::Brush br;


	br.texture = std::string(ASSET_PATH) + "movieback.png"; // backround 
	graphics::drawRect(CANVAS_HEIGHT / 2, CANVAS_WIDTH / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
	graphics::setWindowBackground(br);

	drawYear(this->getYear());
	drawProd(this->getId());
	drawGenre(this->getId());
	drawSummary(this->getId());
	drawTitle(this->getTitle());
	drawPicture(this->getId());
	drawDirector(this->getDirector());
	drawBack(back);


}

void Movie::update()
{
}


Movie::Movie() {}
Movie::~Movie()
{
}
//default constructor 


Movie::Movie(std::string title, int year, std::string director) {
	setDirector(director);
	setTitle(title);
	setYear(year);
	this->genre_list.fill("");
	k++;
	this->id = k;

}

void Movie::startM() {}

std::string Movie::getTitle() {
	return this->title;

}
void Movie::setTitle(std::string title) {
	this->title = title;
}
std::string Movie::getDirector() {
	return this->director;
}
void Movie::setDirector(std::string director) {
	this->director = director;
}
int Movie::getYear() {
	return this->year;
}
void Movie::setYear(int year) {
	this->year = year;

}
std::array<std::string,3> Movie::getGenre() {
	
	return this->genre_list;
}

void  Movie::addGenre(std::string genre) {

	for (int i = 0; i < 3; ++i) {
		if (genre_list[i].empty()) {
			genre_list[i] = genre;
			return; // Exit the loop once added
		}
	}
}


int Movie::getId() {
	return this->id;
}

