// Header file for TrackLocation Class
// Daniel Ruiz
// 11/17/21

#ifndef TRACKLOCATION_H  // (include guard) if tracklocation is not defined
#define TRACKLOCATION_H
#include <string>

using namespace std;

class TrackLocation
{
private:
	TrackLocation* next;
	bool banana;
	int hit;

public:
	TrackLocation* getNext() const;
	void setNext(TrackLocation*);
	bool hasBanana() const;
	void placeBanana();
	bool hitBanana();
	TrackLocation();

};
#endif