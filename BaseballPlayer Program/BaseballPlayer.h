// Header file for BaseballPlayer Class
// Daniel Ruiz
// 9/24/21

#ifndef BASEBALLPLAYER_H  // (include guard) if baseballplayer is not defined
#define BASEBALLPLAYER_H
#include <string>

using namespace std;

class BaseballPlayer
{
private:
	string fname;
	string lname;
	int AB;
	int singles;
	int doubles;
	int triples;
	int HR;
public:
	BaseballPlayer();
	string getName() const;
	void setName(string, string);
	int getAB() const;
	int getSingles() const;
	int getDoubles() const;
	int getTriples() const;
	int getHR() const;
	double getAvg() const;
	double getSlg() const;
	void setStats(int, int, int, int, int);
	void init(string, string);
};
#endif