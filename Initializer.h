#pragma once
#include "MovieDAO.h"

 class Initializer {
	 
  private :
	  MovieDAO* moviedao = new MovieDAO();
	  
  public:
	  MovieDAO& getMovieDAO();
	  void prepareData();
	  Initializer();
		   
};
