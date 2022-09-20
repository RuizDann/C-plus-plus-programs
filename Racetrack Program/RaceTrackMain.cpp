// Main for Program 2 Race Track
// Daniel Ruiz

#include "Vehicle.h"
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void printTrack(TrackLocation*, Vehicle[], long, long);
void printLocation(TrackLocation*, Vehicle[], long);

int main() {
	srand(time(0)); //random number seed
	TrackLocation* head = nullptr;
	TrackLocation* temp;
	TrackLocation* newNode;
	TrackLocation* nodeToDelete;
	const long MAXVEHICLES = 8;
	const long MAXLAPS = 5;
	Vehicle cars[MAXVEHICLES];
	long numCars;
	long numLaps;
	long nextCarLoc = 0;
	long currCarLoc = 0;
	long moves;
	char choice;

	head = new TrackLocation;
	temp = head;

	//Create circular linked list
	for (int i = 0; i < MAXVEHICLES - 1; ++i) {
		newNode = new TrackLocation;
		temp->setNext(newNode);
		temp = newNode;
	}
	
	newNode->setNext(head);

	cout << "How many racecars are there? ";
	cin >> numCars;

	//Validates the number of RACERS is between 1 and 8
	while (numCars < 1 || numCars > MAXVEHICLES) {
		cout << "Invalid number of racecars. Number must be between 1 and 8." << endl;
		cout << "How many racecars? ";
		cin >> numCars;
	}

	cout << "How many laps are they doing? ";
	cin >> numLaps;

	//Validates the number of LAPS is between 1 and 5
	while (numLaps < 1 || numLaps > MAXLAPS) {
		cout << "Invalid number of laps. Number must be between 1 and 5." << endl;
		cout << "How many laps are they doing? ";
		cin >> numLaps;
	}

	//Initialize racers statistics
	for (int i = 0; i < numCars; ++i) {
		cars[i].init(head, i + 1, numLaps);
	}

	//Start of game
	printTrack(head, cars, numCars, nextCarLoc);
	do
	{
		//Skips cars turn if banana is hit
		if (cars[nextCarLoc].wasSkipped()) {
			if (nextCarLoc == numCars - 1) {
				currCarLoc = 0;
			}
			else {
				currCarLoc = nextCarLoc + 1;
			}
		}
		else {
			currCarLoc = nextCarLoc;
		}

		//back to car 1 if final car has moved
		if (currCarLoc == numCars - 1) {
			nextCarLoc = 0;
		}
		else {
			nextCarLoc = currCarLoc + 1;
		}

		cin >> choice;

		//Rand num to allow car to move 1 to 3 spaces
		moves = rand() % 3 + 1; 

		for (int i = 0; i < moves; ++i) {
			cars[currCarLoc].setLocation(cars[currCarLoc].getLocation()->getNext());
			
			if (cars[currCarLoc].getLocation()->hasBanana()) {
				
				//Ends cars turn if banana is hit
				if (cars[currCarLoc].getLocation()->hitBanana()) {
					cars[currCarLoc].skip();
					i = 4; 
				}
			}
			
			if (cars[currCarLoc].getLocation() == head) {
				cars[currCarLoc].finishLap();
			}
		}

		//Places banana at cars location
		if ((choice == 'B' || choice == 'b') && cars[currCarLoc].hasBanana()) {
			cars[currCarLoc].useBanana();
			cars[currCarLoc].getLocation()->placeBanana();
		}
		printTrack(head, cars, numCars, nextCarLoc);
	} while (cars[currCarLoc].getLaps() != 0);

	cout << endl;
	cout << "*** Racecar " << currCarLoc + 1 << " is the winner! ***" << endl;
	cout << endl;

	// Deletes list
	int deletedNodes = 0;
	nodeToDelete = head;
	do {
		temp = nodeToDelete->getNext();
		delete nodeToDelete;
		nodeToDelete = temp;
		deletedNodes++;
	} while (nodeToDelete != head);
	
	//prints message if all nodes are deleted successfully
	if (deletedNodes == MAXVEHICLES) {
		cout << "Race track was successfully deleted!" << endl;
	}
	return 0;
}

/*----------------------------------------------------------------------------------*/

void printTrack(TrackLocation* head, Vehicle cars[], long numCars, long nextCarLoc) {
	//Clears system screen
	system("cls");

	//Calls printLocation()
	TrackLocation* currNode;
	if (head != nullptr) {
		currNode = head;
		
		do {
			printLocation(currNode, cars, numCars);
			currNode = currNode->getNext();
		} while (currNode != head);
		cout << "|";
	}
	cout << endl;

	//Prints empty spaces between the track and race info
	for (int i = 0; i < 11; ++i) {
		cout << "  ";
		
		for (int j = 0; j < numCars; ++j) {
			cout << " ";
		}
		cout << " ";
	}

	//prints titles
	cout << endl << setw(10) << "Racecar";
	cout << setw(8) << "To Go";
	cout << setw(10) << "Ability" << endl;

	//prints current cars turn, car number, laps left, and if they have a banana
	for (int i = 0; i < numCars; ++i) {
		if (nextCarLoc == i) {
			cout << "*" << setw(9) << i + 1;
		}
		else {
			cout << setw(10) << i + 1;
		}
		cout << setw(8) << cars[i].getLaps();
		
		//prints if the car has a banana, else becomes empty
		if (cars[i].hasBanana() == true) { 
			cout << setw(10) << "Banana";
		}
		else {
			cout << setw(10) << "      ";
		}
		cout << endl;
	}
}

void printLocation(TrackLocation* vLoc, Vehicle cars[], long numCars) {
	//prints outer left vertical bar
	cout << "|"; 

	// places banana if car has one, else leaves empty
	if(vLoc->hasBanana()) { 
		cout << "B"; 
	} 
	else {
		cout << " "; 
	}

	//prints car in spot, else leaves empty spaces on the track
	for (int j = 0; j < numCars; ++j) {
		
		if (cars[j].getLocation() == vLoc) {
			cout << cars[j].getID();
		}
		else {
			cout << " "; 
		}
	}
	cout << " ";
}
