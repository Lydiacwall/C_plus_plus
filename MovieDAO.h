#pragma once
#include "movie.h"

class MovieDAO {

public:
	std::array<Movie,N> movie_list;
	void save(Movie new_movie);
	Movie findByTitle(std::string movie_name);
	Movie findByYear(int year);
	Movie findByDirector(std::string director);
	std::array<Movie,6> findByGenre(std::string genre);
	MovieDAO();


};