#include "BaseballPlayer.h"
#include <iostream>

using namespace std;

int main()
{
	BaseballPlayer p;

	if (p.getName() != "None None")
		cout << "Error in constructor 1.\n";

	if (p.getAB() != 0)
		cout << "Error in constructor 2.\n";

	if (p.getAvg() != 0)
		cout << "Error in constructor 3\n.";

	if(p.getSingles() != 0)
		cout << "Error in constructor 4\n.";

	if (p.getDoubles() != 0)
		cout << "Error in constructor 5\n.";

	if (p.getTriples() != 0)
		cout << "Error in constructor 6\n.";

	if (p.getHR() != 0)
		cout << "Error in constructor 7\n.";

	p.init("Player", "One");

	if (p.getName() != "Player One")
		cout << "Error in init 1.\n";

	if (p.getAB() != 0)
		cout << "Error in init 2.\n";

	if (p.getSlg() != 0)
		cout << "Error in init 3.\n";

	if (p.getSingles() != 0)
		cout << "Error in init 4\n.";

	if (p.getDoubles() != 0)
		cout << "Error in init 5\n.";

	if (p.getTriples() != 0)
		cout << "Error in init 6\n.";

	if (p.getHR() != 0)
		cout << "Error in init 7\n.";

	p.setStats(5, 1, 1, 1, 1);

	if (p.getSingles() != 1)
		cout << "Error in setStats 1\n.";

	if (p.getDoubles() != 1)
		cout << "Error in setStats 2\n.";

	if (p.getTriples() != 1)
		cout << "Error in setStats 3\n.";

	if (p.getHR() != 1)
		cout << "Error in setStats 4\n.";

	if (p.getAB() != 5)
		cout << "Error in setStats 5.\n";

	if (p.getSlg() != 2)
		cout << "Error in setStats 6.\n";

	if (p.getAvg() != .8)
		cout << "Error in setStats 7.\n";

	//invalid parameters
	p.setStats(5, 4, 3, 2, 1);
	
	if (p.getSingles() != 1)
		cout << "Error in setStats 8.\n";

	if (p.getDoubles() != 1)
		cout << "Error in setStats 9.\n";

	if (p.getTriples() != 1)
		cout << "Error in setStats 10.\n";

	if (p.getHR() != 1)
		cout << "Error in setStats 11.\n";

	if (p.getAB() != 5)
		cout << "Error in setStats 12.\n";

	if (p.getSlg() != 2)
		cout << "Error in setStats 13.\n";

	if (p.getAvg() != .8)
		cout << "Error in setStats 14.\n";

	//valid parameters
	p.setStats(8, 1, 2, 2, 1);

	if (p.getAB() != 8)
		cout << "Error in setStats 15.\n";

	if (p.getSlg() != (15.0/8))
		cout << "Error in setStats 16.\n";

	if (p.getAvg() != .75)
		cout << "Error in setStats 17.\n";

	if (p.getSingles() != 1)
		cout << "Error in setStats 18\n.";

	if (p.getDoubles() != 2)
		cout << "Error in setStats 19\n.";

	if (p.getTriples() != 2)
		cout << "Error in setStats 20\n.";

	if (p.getHR() != 1)
		cout << "Error in setStats 21\n.";


	cout << "Testing complete.\n";
	system("pause");
	return 0;
}

void e(int loc)
{
	cout << "Error in location " << loc << endl;
}