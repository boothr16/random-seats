//header file for Student class
#ifndef STUDENT
	#define STUDENT

#include <iostream>
#include <string>
using namespace std;

class Student
{
public: 
	Student(); //default constructor
	Student(string, string); //parameterized constructor
	const Student& operator=(const Student&); //overloaded assignment operator
	friend ostream& operator<<(ostream&, const Student&); //overloaded extraction/output operator

private:
	string Last, First;
};
#endif
