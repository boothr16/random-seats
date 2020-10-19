//implementation file for Student class
#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

Student::Student() //default constructor
{
	First, Last = " ";
}

Student::Student(string F, string L) //parameterized constructor
{
	Last = L;
	First = F;
}

const Student& Student::operator=(const Student& s) //allows for assignment
{
	// bypass self assignment
	if (this != &s)
	{
		Last = s.Last;
		First = s.First;
	}
	return *this;
}

ostream& operator<<(ostream& out, const Student& s) //allows for output
{
	out << s.First << " " << s.Last;
	return out;
}