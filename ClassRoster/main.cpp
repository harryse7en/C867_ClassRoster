#include "roster.h"
#include "student.h"
#include <iostream>
#include <sstream>

using namespace std;

int main()
{

    // Sample data for testing
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Harvey,Sanford,harvsan@example.edu,37,5,10,100,SOFTWARE" };

    cout << "********   CLASS ROSTER   ********\n";
    cout << "    by harryse7en, 01-Feb-2022\n\n";
    cout << "This console application was created during a college course to meet requirements of a basic Class Roster using Visual Studio 2022.\n";
    cout << "This application represents the final solution to pass the course.\n\n\n\n";

    Roster classRoster;

    // Populate the roster with each student
    for (int i = 0; i < 5; i++) {
        classRoster.add(studentData[i]);
    }

    // Pseudo code functions and testing
    cout << "LIST OF ALL CURRENT STUDENTS:\n";
    classRoster.printAll();
    cout << "\nLIST OF ALL INVALID EMAIL ADDRESSES:\n";
    classRoster.printInvalidEmails();
    cout << "\nLIST OF EACH STUDENT'S AVERAGE DAYS IN A COURSE:\n";
    for (int i = 0; i < 5; i++) {
        classRoster.printAverageDaysInCourse(classRoster.getCurrStudentID(i));
    }
    cout << "\nLIST OF STUDENTS ENROLLED IN \"SOFTWARE\" DEGREE:\n";
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << "\nREMOVING STUDENT \"A3\"\n";
    classRoster.remove("A3");
    cout << "LIST OF ALL CURRENT STUDENTS:\n";
    classRoster.printAll();
    cout << "\nREMOVING STUDENT \"A3\" (should cause an error)\n";
    classRoster.remove("A3");

    // De-constructor to release memory
    classRoster.~Roster();

}
