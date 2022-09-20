// Main file for BaseballPlayer Class
// Daniel Ruiz
// 9/24/21

#include "BaseballPlayer.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAXPLAYERS = 9;

void readPlayerInfo(BaseballPlayer baseballPlayer[], int i)
{
	string first, last;
	int atBat, sin, doub, trip, homeR;

	cout << "What is the first name of player " << i << "?" << endl;
	cin >> first;
	cout << "What is the last name of player " << i << "?" << endl;
	cin >> last;

	baseballPlayer[i].setName(first, last);

	cout << "How many at-bats did " << baseballPlayer[i].getName() << " have?" << endl;
	cin >> atBat;
	cout << "How many singles did " << baseballPlayer[i].getName() << " have?" << endl;
	cin >> sin;
	cout << "How many doubles did " << baseballPlayer[i].getName() << " have?" << endl;
	cin >> doub;
	cout << "How many triples did " << baseballPlayer[i].getName() << " have?" << endl;
	cin >> trip;
	cout << "How many home runs did " << baseballPlayer[i].getName() << " have?" << endl;
	cin >> homeR;

	baseballPlayer[i].setStats(atBat, sin, doub, trip, homeR);
}

void selectionSortName(BaseballPlayer baseballPlayer[], int numPlayers) {
	int i = 0;
	int j = 0;
	int indexSmallest = 0;
	BaseballPlayer temp;  // Temporary variable for swap

	for (i = 1; i < numPlayers; ++i) {

		// Find index of smallest remaining element
		indexSmallest = i;
		for (j = i + 1; j < numPlayers; ++j) {

			if (baseballPlayer[j].getName() < baseballPlayer[indexSmallest].getName()) {
				indexSmallest = j;
			}
		}

		// Swap numbers[i] and numbers[indexSmallest]
		temp = baseballPlayer[i];
		baseballPlayer[i] = baseballPlayer[indexSmallest];
		baseballPlayer[indexSmallest] = temp;
	}
}

void selectionSortSlug(BaseballPlayer baseballPlayer[], int numPlayers) {
	int i = 0;
	int j = 0;
	int indexLargest = 0;
	BaseballPlayer temp;  // Temporary variable for swap

	for (i = 1; i < numPlayers; ++i) {

		// Find index of smallest remaining element
		indexLargest = i;
		for (j = i + 1; j < numPlayers; ++j) {

			if (baseballPlayer[j].getSlg() > baseballPlayer[indexLargest].getSlg()) {
				indexLargest = j;
			}
		}

		// Swap numbers[i] and numbers[indexSmallest]
		temp = baseballPlayer[i];
		baseballPlayer[i] = baseballPlayer[indexLargest];
		baseballPlayer[indexLargest] = temp;
	}
}

void printPlayers(BaseballPlayer baseballPlayer[], int i)
{
	cout << right << setw(20) << baseballPlayer[i].getName();
	cout << right << setw(6) << fixed << setprecision(3) << baseballPlayer[i].getAvg();
	cout << right << setw(6) << fixed << setprecision(3) << baseballPlayer[i].getSlg() << endl;

}

int main() {
	
	int numPlayers = MAXPLAYERS;
	BaseballPlayer baseballPlayer[MAXPLAYERS];
	int i;

	cout << "How many baseball players are there?" << endl;
	cin >> numPlayers;
	numPlayers = numPlayers + 1;

	// for loop to take in all players info
	for (int i = 1; i < numPlayers; i++) {
		readPlayerInfo(baseballPlayer, i);
	}
	
	cout << "Players by name:" << endl;
	cout << right << setw(20) << "Name";
	cout << right << setw(6) << "SLG";
	cout << right << setw(6) << "AVG" << endl;
	
	selectionSortName(baseballPlayer, numPlayers); //sort players by getName
	
	for (int i = 1; i < numPlayers; i++) {
	printPlayers(baseballPlayer, i);
	}
	cout << endl;

	cout << "Players by slugging:" << endl;
	cout << right << setw(20) << "Name";
	cout << right << setw(6) << "SLG";
	cout << right << setw(6) << "AVG" << endl;

	selectionSortSlug(baseballPlayer, numPlayers); //sort players by getSlg

	for (int i = 1; i < numPlayers; i++) {
	printPlayers(baseballPlayer, i);
	}

	return 0;
}