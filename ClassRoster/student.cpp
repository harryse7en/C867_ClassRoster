#include "student.h"
#include <iostream>

using namespace std;

// Accessor functions
string Student::getStudentID() const {
	return studentID;
}

string Student::getFirstName() const{
	return firstName;
}

string Student::getLastName() const{
	return lastName;
}

string Student::getEmailAddress() const{
	return emailAddress;
}

int Student::getAge() const{
	return age;
}

int Student::getDaysInCourse1() const {
	return daysInCourse[0];
}

int Student::getDaysInCourse2() const {
	return daysInCourse[1];
}

int Student::getDaysInCourse3() const {
	return daysInCourse[2];
}

DegreeProgram Student::getDegreeProgram() const{
	return degreeProgram;
}

string Student::getDegreeProgramStr() const {
	switch (degreeProgram) {
		case DegreeProgram::SECURITY:
			return "SECUIRTY"; break;
		case DegreeProgram::NETWORK:
			return "NETWORK"; break;
		case DegreeProgram::SOFTWARE:
			return "SOFTWARE"; break;
		default:
			return "NONE";
	}
}



// Mutator functions
void Student::setStudentID(string pStudentID) {
	studentID = pStudentID;
}

void Student::setFirstName(string pFirstName) {
	firstName = pFirstName;
}

void Student::setLastName(string pLastName) {
	lastName = pLastName;
}

void Student::setEmailAddress(string pEmailAddress) {
	emailAddress = pEmailAddress;
}

void Student::setAge(int pAge) {
	age = pAge;
}

void Student::setDaysInCourse1(int pDaysInCourse) {
	daysInCourse[0] = pDaysInCourse;
}

void Student::setDaysInCourse2(int pDaysInCourse) {
	daysInCourse[1] = pDaysInCourse;
}

void Student::setDaysInCourse3(int pDaysInCourse) {
	daysInCourse[2] = pDaysInCourse;
}

void Student::setDegreeProgram(DegreeProgram pDegreeProgram) {
	degreeProgram = pDegreeProgram;
}



// Constructors
Student::Student() {
	setStudentID("");
	setFirstName("");
	setLastName("");
	setEmailAddress("");
	setAge(0);
	setDaysInCourse1(0);
	setDaysInCourse2(0);
	setDaysInCourse3(0);
	setDegreeProgram(DegreeProgram::NONE);
}

Student::Student(string pStudentID, string pFirstName, string pLastName, string pEmailAddress, int pAge, int pDaysInCourse1, int pDaysInCourse2, int pDaysInCourse3, DegreeProgram pDegreeProgram) {
	setStudentID(pStudentID);
	setFirstName(pFirstName);
	setLastName(pLastName);
	setEmailAddress(pEmailAddress);
	setAge(pAge);
	setDaysInCourse1(pDaysInCourse1);
	setDaysInCourse2(pDaysInCourse2);
	setDaysInCourse3(pDaysInCourse3);
	setDegreeProgram(pDegreeProgram);
}



// Print function
void Student::print() {
	cout << "ID: " << getStudentID() << "\t";
	cout << "Name: " << getFirstName() << " " << getLastName() << "\t";
	//cout << "Email: " << getEmailAddress() << "\t";
	cout << "Age: " << getAge() << "\t";
	cout << "daysInCourse: {" << getDaysInCourse1() << ", " << getDaysInCourse2() << ", " << getDaysInCourse3() << "}\t";
	cout << "Degree: " << getDegreeProgramStr() << "\n";
}



Student::~Student() {

}
