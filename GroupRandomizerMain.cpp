/********************************************************************
Name: Robert Booth
Date: August 30th, 2020

Group Randomizer

Takes a class roster of students' names, and randomly puts them in groups of 4.
Names in input file are stored in the format "lastName, firstName middleInitial."

Inputs: Class roster file (ifstream), student names (strings)
Output: Randomized student groups output to monitor.
********************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h> //rand() and srand()
#include <time.h> //time()
#include "Student.h"

int main()
{
	// 1. Declare variables
	int numStudents = 0;
	int groupCounter = 1;
	ifstream inFile("roster.txt"); //connect to input file
	vector<Student> fullRoster; //vector that will store student names
	string lastName;
	string firstName;

	// 2. Read the roster file into vector
	while (!inFile.eof()) //while NOT at EOF
	{
		getline(inFile, lastName, ',');
		inFile >> firstName;
		Student fullName(firstName, lastName);
		fullRoster.push_back(fullName); //add student to the end of the vector
		inFile.ignore(100, '\n'); //go to next line (ignores middle initial, if any)
	}

	// 3. Get number of students from vector
	numStudents = fullRoster.size();

	// 4. Output heading for first group
	cout << "GROUP #" << groupCounter << endl;
	groupCounter += 1;

	// 5. Randomize student groups
	srand(time(NULL)); //use system clock to seed RNG
	for (int i = 0; i < numStudents; i++) //pick a random student numStudents times
	{
		if (i % 4 == 0 && i != 0) //if the previous group already has 4 students
		{
			cout << "\nGROUP #" << groupCounter << endl; //start new group
			groupCounter += 1; //increase groupCounter by 1
		}
		int randElement = rand() % fullRoster.size(); //pick a random element in fullRoster vector
		cout << fullRoster.at(randElement) << endl; //output student at that random position in the roster
		fullRoster.erase(fullRoster.begin()+randElement); //remove student from vector to avoid double-picking
	}
}
