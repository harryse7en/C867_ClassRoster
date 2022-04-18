#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>

using namespace std;

class Student {

private:

	string studentID, firstName, lastName, emailAddress;
	int age, daysInCourse[3];
	DegreeProgram degreeProgram;

public:

	// Accessor function declarations
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	int getDaysInCourse1() const;
	int getDaysInCourse2() const;
	int getDaysInCourse3() const;
	DegreeProgram getDegreeProgram() const;
	string getDegreeProgramStr() const;

	// Mutator function declarations
	void setStudentID(string pStudentID);
	void setFirstName(string pFirstName);
	void setLastName(string pLastName);
	void setEmailAddress(string pEmailAddress);
	void setAge(int pAge);
	void setDaysInCourse1(int pDaysInCourse1);
	void setDaysInCourse2(int pDaysInCourse2);
	void setDaysInCourse3(int pDaysInCourse3);
	void setDegreeProgram(DegreeProgram pDegreeProgram);

	// Constructor declarations
	Student();
	Student(string pStudentID, string pFirstName, string pLastName, string pEmailAddress, int pAge, int pDaysInCourse1, int pDaysInCourse2, int pDaysInCourse3, DegreeProgram pDegreeProgram);
	
	// Print function declaration
	void print();

	// De-constructor declaration
	~Student();

};

#endif
