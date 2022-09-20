// CPP file Vehicle Class
// Daniel Ruiz

#include "Vehicle.h"
#include <iostream>
#include <string>

using namespace std;

TrackLocation* Vehicle::getLocation()
{
	return vehicleLocation;
}

void Vehicle::setLocation(TrackLocation* vLoc)
{
	vehicleLocation = vLoc;
}

bool Vehicle::hasBanana()
{
	return banana;
}

void Vehicle::useBanana()
{
	banana = false;
}

int Vehicle::getLaps()
{
	return laps;
}

void Vehicle::finishLap()
{
	--laps;
}

int Vehicle::getID() const
{
	return ID;
}

bool Vehicle::wasSkipped()
{
	if (skipTurn == true) {
		skipTurn = false;
		return true;
	}
	else {
		return false;
	}
}

void Vehicle::skip()
{
	skipTurn = true;
}

void Vehicle::init(TrackLocation* vLoc, int vicID, int vicLaps)
{
	vehicleLocation = vLoc;
	ID = vicID;
	laps = vicLaps;
	banana = true;
}
