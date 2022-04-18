#ifndef ROSTER_H
#define ROSTER_H

#include "degree.h"
#include "student.h"
#include <string>

using namespace std;

class Roster {

private:

	int classRosterIndex = 0;
	Student* classRosterArray[5];


public:
	
	Roster();

	// Add student function declaration
	void add(string pStudentData);

	// Remove student function declaration
	void remove(string pStudentID);

	// Print tab-separated list function declaration
	void printAll();

	// Print avg. days in class function declaration
	void printAverageDaysInCourse(string pStudentID);

	// Print invalid emails function declaration
	void printInvalidEmails();

	// Print by degree program function declaration
	void printByDegreeProgram(DegreeProgram pDegreeProgram);

	// Accessor function declaration
	string getCurrStudentID(int idx) const;

	// De-constructor declaration
	~Roster();

};

#endif
