// CPP file for BaseballPlayer Class
// Daniel Ruiz
// 9/24/21

#include "BaseballPlayer.h"
#include <iostream>

string BaseballPlayer::getName() const
{
	return (fname + " " + lname);
}

void BaseballPlayer::setName(string first, string last)
{
	fname = first;
	lname = last;
}

int BaseballPlayer::getAB() const
{
	return AB;
}

int BaseballPlayer::getSingles() const
{
	if ((singles + doubles + triples + HR) > AB) {
		return 1;
	}
	else {
		return singles;
	}
}

int BaseballPlayer::getDoubles() const
{
	if ((singles + doubles + triples + HR) > AB) {
		return 1;
	}
	else {
	return doubles;
	}
}

int BaseballPlayer::getTriples() const
{
	if ((singles + doubles + triples + HR) > AB) {
		return 1;
	}
	else {
		return triples;
	}
}

int BaseballPlayer::getHR() const
{
	return HR;
}

double BaseballPlayer::getAvg() const
{
	double AVG;
	if (AB == 0) {
		return 0;
	}
	if (singles == 0 && doubles == 0 && triples == 0 && HR == 0) {
		AVG = 0;
		return AVG;
	}
	if ((singles + doubles + triples + HR) > AB) {
		AVG = 4.0 / double(AB);
		return AVG;
	}
	else {
		AVG = (double(singles) + double(doubles) + double(triples) + double(HR)) / double(AB);
		return AVG;
	}
}

double BaseballPlayer::getSlg() const
{
	double SLG;
	if (AB == 0) {
		return 0;
	}
	if (singles == 0 && doubles == 0 && triples == 0 && HR == 0) {
		SLG = 0;
		return SLG;
	}
	if ((singles + doubles + triples + HR) > AB) {
		SLG = (singles + doubles + triples + HR) / AB;
		return SLG;
	}
	if ((singles + doubles + triples + HR) < AB) {
		SLG = (double(singles) + (double(doubles) * 2) + (double(triples) * 3) + (double(HR) * 4)) / AB;
		return SLG;
	}
	else {
		SLG = (singles + (doubles * 2) + (triples * 3) + (HR) * 4) / AB;
		return SLG;
	}
}

void BaseballPlayer::setStats(int atBat, int sin, int doub, int trip, int homeR)
{
	if (atBat >= 0) {
		AB = atBat;
	}
	if (sin >= 0) {
		singles = sin;
	}
	if (doub >= 0) {
		doubles = doub;
	}
	if (trip >= 0) {
		triples = trip;
	}
	if (homeR >= 0) {
		HR = homeR;
	}
}

BaseballPlayer::BaseballPlayer()
{
	fname = "None";
	lname = "None";
	AB = 0;
	singles = 0;
	doubles = 0;
	triples = 0;
	HR = 0;
}

void BaseballPlayer::init(string first, string last)
{
	fname = first; 
	lname = last;
}