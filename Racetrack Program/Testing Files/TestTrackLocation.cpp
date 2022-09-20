#include "TrackLocation.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	TrackLocation *testLoc, *testLoc2, *testLoc3;
	int count, hits = 0;

	srand(time(0));

	testLoc = new TrackLocation;

	if (testLoc->hasBanana())
		cout << "Error in constructor 1.\n";
	if (testLoc->getNext() != nullptr)
		cout << "Error in constructor 2.\n";

	testLoc2 = new TrackLocation;
	testLoc->setNext(testLoc2);
	if (testLoc->getNext() != testLoc2)
		cout << "Error in get/set next.\n";

	testLoc->placeBanana();
	if (!testLoc->hasBanana())
		cout << "Error in place/has banana.\n";

	testLoc->placeBanana();
	if (!testLoc->hasBanana())
		cout << "Error in place banana.\n";

	count = 10;
	while (testLoc->hasBanana() && count > 0)
	{
		testLoc->hitBanana();
		count--;
	}

	if (count == 0)
	{
		cout << "Error hitting banana 1!\n";
	}
	
	testLoc->placeBanana();
	count = 10;
	while (count > 0)
	{
		testLoc->hitBanana();
		count--;
	}

	if (testLoc->hasBanana())
	{
		cout << "Error hitting banana 2!\n";
	}
	
	count = 100;
	while (count > 0)
	{
		testLoc->placeBanana();

		if (testLoc->hitBanana())
			hits++;

		count--;
	}

	if (hits > 60 || hits < 40)
		cout << "Error hitting banana 3!\n";

	delete testLoc;
	delete testLoc2;

	testLoc = new TrackLocation;
	testLoc2 = new TrackLocation;
	testLoc3 = new TrackLocation;

	testLoc->setNext(testLoc2);

	if (testLoc->getNext() != testLoc2)
		cout << "Error with get/set next 1!\n";

	testLoc2->setNext(testLoc3);

	if (testLoc2->getNext() != testLoc3)
		cout << "Error with get/set next 2!\n";

	testLoc3->setNext(testLoc);

	if (testLoc3->getNext() != testLoc)
		cout << "Error with get/set next 3!\n";


	cout << "Testing complete!\n";
	return 0;
}