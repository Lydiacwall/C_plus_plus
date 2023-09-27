#include "MovieDAO.h" 
#include <array>

void MovieDAO::save(Movie new_movie) {
	movie_list[new_movie.getId() - 1] = new_movie;
}

Movie MovieDAO::findByTitle(std::string movie_name) {

	for (Movie i : movie_list) {
		if (i.getTitle() == movie_name) {
			return i;
		}
	}
}

Movie MovieDAO::findByYear(int year) {
	for (Movie i : movie_list) {
		if (i.getYear() == year) {
			return i;
		}
	}

}

Movie  MovieDAO::findByDirector(std::string director) {
	for (Movie i : movie_list) {
		if (i.getDirector() == director) {
			return i;
		}
	}
}

std::array<Movie,6> MovieDAO::findByGenre(std::string genre) {
	std::array<Movie,6> movieListByGenre;
	int pos = 0;
	for (Movie i : movie_list) {
		for (std::string j : i.getGenre()) {
			if (j == genre) {
				movieListByGenre[pos]=i;
				pos++;
			}
		}
		
	}
	return movieListByGenre;

}

MovieDAO::MovieDAO() {

}
