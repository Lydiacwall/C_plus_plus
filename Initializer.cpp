#pragma once
#include "Initializer.h"



MovieDAO& Initializer::getMovieDAO() {
	return *moviedao;

}

void Initializer::prepareData() {
	Movie a = Movie("Fight Club", 1999, "David Fincher"); //id=1
	a.addGenre("thriller");
	a.addGenre("drama");

	Movie b = Movie("The Hunger Games", 2012, "Gary Ross"); //id=2
	b.addGenre("action");
	b.addGenre("adventure");
	b.addGenre("scifi");

	Movie c = Movie("Avatar", 2009, "James Cameron");//id=3
	c.addGenre("action");
	c.addGenre("adventure");
	c.addGenre("fantasy");

	Movie d = Movie("Pulp Fiction", 1994, "Quentin Tarantino");//id=4
	
	d.addGenre("crime");
	d.addGenre("drama");
	
	Movie e = Movie("Rush Hour", 1998, "Brett Ratner");//id=5
	
	e.addGenre("crime");
	e.addGenre("action");
	e.addGenre("comedy");
	
	Movie f = Movie("The Grinch", 2000, "Ron Howard");//id=6
	f.addGenre("fantasy");
	f.addGenre("family");
	f.addGenre("comedy");
		
	Movie g = Movie("Elf", 2003, "Jon Favreau");//id=7
	g.addGenre("adventure");
	g.addGenre("comedy");
	g.addGenre("family");
	
	Movie h = Movie("Lights Out", 2016, "David F.Sandberg"); //id=8
	h.addGenre("horror");
	h.addGenre("mystery");
	
	Movie i = Movie("No Time to Die", 2021, "Cary Joji Fukunaga"); //id=9
	i.addGenre("action");
	i.addGenre("adventure");
	i.addGenre("thriller");
	
	Movie j = Movie("Star Wars", 1999, "George Lucas"); //id=10
	j.addGenre("action");
	j.addGenre("adventure");
	j.addGenre("fantasy");

	Movie k = Movie("Eyes Wide Shut", 1999, "Stanley Kubrick"); //id=11
	k.addGenre("drama");
	k.addGenre("mystery");
	k.addGenre("thriller");

	Movie l = Movie("A Clockwork Orange", 1971, "Stanley Kubrick"); //id=12
	l.addGenre("scifi");
	l.addGenre("crime");
	
	Movie m = Movie("Malena", 2000, "Giuseppe Tornatore"); //id=13
	m.addGenre("drama");
	m.addGenre("romance");
	m.addGenre("war");
	
	Movie n = Movie("Requiem for a Dream", 2000, "Darren Aronofsky"); //id=14
	n.addGenre("drama");

	Movie o = Movie("Kill Bill", 2003, "Quentin Tarantino"); //id=15
	m.addGenre("drama");
	m.addGenre("action");
	m.addGenre("drama");
	
	
	moviedao->save(a);
	moviedao->save(b);
	moviedao->save(c);
	moviedao->save(d);
	moviedao->save(e);
	moviedao->save(f);
	moviedao->save(g);
	moviedao->save(h);
	moviedao->save(i);
	moviedao->save(j);
	moviedao->save(k);
	moviedao->save(l);
	moviedao->save(m);
	moviedao->save(n);
	moviedao->save(o);

}

Initializer::Initializer() {

	moviedao = new MovieDAO();
}