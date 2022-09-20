#include "Vehicle.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	TrackLocation *testLoc;
	Vehicle v;

	srand(time(0));

	testLoc = new TrackLocation;

	v.init(testLoc, 4, 5);

	if (v.getID() != 4)
		cout << "Error in init 1!\n";

	if(v.getLocation() != testLoc)
		cout << "Error in init 2!\n";

	if (v.getLaps() != 5)
		cout << "Error in init 3!\n";

	if(!v.hasBanana())
		cout << "Error in init 4!\n";

	if (v.wasSkipped())
		cout << "Error in init 5!\n";


	v.finishLap();

	if (v.getLaps() != 4)
		cout << "Error in getLaps 1!\n";

	v.finishLap();

	if (v.getLaps() != 3)
		cout << "Error in getLaps 2!\n";

	v.useBanana();
	if (v.hasBanana())
		cout << "Error in useBanana 1!\n";

	v.useBanana();
	if (v.hasBanana())
		cout << "Error in useBanana 2!\n";

	delete testLoc;
	testLoc = new TrackLocation;

	v.setLocation(testLoc);

	if (v.getLocation() != testLoc)
		cout << "Error in set location !\n";

	v.skip();

	if (!v.wasSkipped())
		cout << "Error in wasSkipped 1 !\n";

	if (v.wasSkipped())
		cout << "Error in wasSkipped 2 !\n";

	cout << "Testing complete!\n";
	return 0;
}