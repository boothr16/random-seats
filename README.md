# random-seats
This program randomizes student groups for chemistry lab

This program takes a class roster as an input file, and creates randomized student groups of a desired size. The program requires the files GroupRandomizerMain.cpp, Student.h, and Student.cpp to run. The program works by iterating through lines in the roster (text file), and pushing the student names into a vector. When the EOF is reached, the students' names are popped from random positions in the vector, and the students are placed into groups. This program was written to help make student groups quickly during class while virtual teaching, due to the ongoing COVID-19 pandemic. Sample input/output is not provided in order to protect student information.
