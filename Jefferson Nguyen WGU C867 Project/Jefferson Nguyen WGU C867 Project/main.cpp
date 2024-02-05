#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main()
{
	cout << "Course Title: Scripting and Programming - Applications - C867" << endl;
	cout << "Programming Language Used: C++" << endl;
	cout << "WGU Student ID: 011322226" << endl;
	cout << "Name: Jefferson Nguyen" << endl;
	cout << endl;

	
	const string studentData[] =
	{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
	 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
	 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
	 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
	 "A5,Jefferson,Nguyen,jngu343@wgu.edu,24,18,38,25,SOFTWARE"
	};

	Roster classRoster; 
	
	for(int i = 0; i < NUM_OF_STUDENTS; i++) 
	{
		classRoster.addStudent(studentData[i]);
	}

	cout << "Printing all Students" << endl;
	classRoster.printAll();
	cout << endl;

	cout << "Printing Invalid Email Addresses" << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	cout << "Student's Average Days in Class" << endl;
	for (int i = 0; i < NUM_OF_STUDENTS; i++) 
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentIdNum());
	}
	cout << endl;

	cout << "Printing Students whos Degree Program is SOFTWARE" << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	cout << "Removing Student A3 from the Roster" << endl;
	classRoster.remove("A3");
	cout << endl;

	cout << "Removing Student A3 from the Roster" << endl;
	classRoster.remove("A3");
	cout << endl;

	cout << "Printing out remaining roster" << endl;
	classRoster.printAll();
	cout << endl;

}