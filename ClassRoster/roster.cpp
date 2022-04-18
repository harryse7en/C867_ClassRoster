#include "roster.h"
#include "student.h"

#include <iostream>
#include <sstream>

using namespace std;

// Constructors
Roster::Roster() {
    classRosterIndex = 0;
    for (int i = 0; i < 5; i++) {
        classRosterArray[i] = new Student();
    }
}

// Add student function
void Roster::add(string pStudentData) {
    // First, the input string must be parsed into useable columns
    stringstream line(pStudentData);
    string substr;
    int daysInCourse[3] = {0,0,0};
    getline(line, substr, ',');
    classRosterArray[classRosterIndex]->setStudentID(substr);
    getline(line, substr, ',');
    classRosterArray[classRosterIndex]->setFirstName(substr);
    getline(line, substr, ',');
    classRosterArray[classRosterIndex]->setLastName(substr);
    getline(line, substr, ',');
    classRosterArray[classRosterIndex]->setEmailAddress(substr);
    getline(line, substr, ',');
    classRosterArray[classRosterIndex]->setAge(atoi(substr.c_str()));
    getline(line, substr, ',');
    classRosterArray[classRosterIndex]->setDaysInCourse1(atoi(substr.c_str()));
    getline(line, substr, ',');
    classRosterArray[classRosterIndex]->setDaysInCourse2(atoi(substr.c_str()));
    getline(line, substr, ',');
    classRosterArray[classRosterIndex]->setDaysInCourse3(atoi(substr.c_str()));
    getline(line, substr, ',');
    if (substr == "SECURITY") {
        classRosterArray[classRosterIndex]->setDegreeProgram(DegreeProgram::SECURITY);
    } else if (substr == "NETWORK") {
        classRosterArray[classRosterIndex]->setDegreeProgram(DegreeProgram::NETWORK);
    } else if (substr == "SOFTWARE") {
        classRosterArray[classRosterIndex]->setDegreeProgram(DegreeProgram::SOFTWARE);
    } else {
        classRosterArray[classRosterIndex]->setDegreeProgram(DegreeProgram::NONE);
    }
    // The index is incremented after each student added
    classRosterIndex++;
}

// Remove student function
void Roster::remove(string pStudentID) {
    bool isFound = false;
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr) {
            if (pStudentID == getCurrStudentID(i)) {
                classRosterArray[i] = nullptr;
                cout << "Student ID " << pStudentID << " removed\n";
                isFound = true;
                break;
            } else {
                continue;
            }
        }
    }
    if (!isFound) {
        cout << "ERROR: Student ID " << pStudentID << " does not exist!\n";
    }
}

// Print tab-separated list function
void Roster::printAll() {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] == nullptr) {
            continue;
        } else {
            classRosterArray[i]->print();
        }
    }
}

// Print avg. days in class function
void Roster::printAverageDaysInCourse(string pStudentID) {
    for (int i = 0; i < 5; i++) {
        if (pStudentID == getCurrStudentID(i)) {
            double avg = (classRosterArray[i]->getDaysInCourse1() + classRosterArray[i]->getDaysInCourse2() + classRosterArray[i]->getDaysInCourse3()) / 3.0;
            cout << "ID \"" << pStudentID << "\" average days in course is:  " << avg << endl;
        }
    }
}

// Print invalid emails function
void Roster::printInvalidEmails() {
    for (int i = 0; i < 5; i++) {
        string email = classRosterArray[i]->getEmailAddress();
        if (email.find(" ") != string::npos || email.find(".") == string::npos || email.find("@") == string::npos) {
            cout << "ID \"" << getCurrStudentID(i) << "\" email address is invalid: " << email << endl;
        }
    }
}

// Print by degree program function
void Roster::printByDegreeProgram(DegreeProgram pDegreeProgram) {
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i]->getDegreeProgram() == pDegreeProgram) {
            classRosterArray[i]->print();
            count++;
        }
    }
    if (count == 0) {
        cout << "There are no students enrolled in this degree program\n";
    }
}

// Accessor function
string Roster::getCurrStudentID(int idx) const {
    return classRosterArray[idx]->getStudentID();

}

Roster::~Roster() {
    
}
