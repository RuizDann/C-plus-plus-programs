// Header file for Vehicle Class
// Daniel Ruiz

#ifndef VEHICLE_H
#define VEHICLE_H

#include "TrackLocation.h"
#include <iomanip>
#include <ctime>

using namespace std;

class Vehicle
{
private:
    TrackLocation* vehicleLocation;
    bool banana;
    bool skipTurn;
    int ID;
    int laps;
    char vehicleID;

public:
    TrackLocation* getLocation();
    void setLocation(TrackLocation*);
    bool hasBanana();
    void useBanana();
    void finishLap();
    int getLaps();
    int getID() const;
    void skip();
    bool wasSkipped();
    void init(TrackLocation*, int, int);
};
#endif 
