// CPP file TrackLocation class
// Daniel Ruiz

#include "TrackLocation.h"
#include <iostream>
#include <ctime>

using namespace std;

TrackLocation* TrackLocation::getNext() const
{
	return next;
}

void TrackLocation::setNext(TrackLocation* nxt)
{
	next = nxt;
}

bool TrackLocation::hasBanana() const
{
	if (banana == true) {
		return true;
	}
	else {
		return false;
	}
}

void TrackLocation::placeBanana()
{
	banana = true;
}

bool TrackLocation::hitBanana()
{
	if (banana == false) {
		return false;
	}
	else {
		hit = rand() % 2;
		if (hit == 1) {
			return false;
		}
		else {
			banana = false;
			return true;
		}
	}
}

TrackLocation::TrackLocation()
{
	next = nullptr;
	banana = false;
	hit = 1;
}
