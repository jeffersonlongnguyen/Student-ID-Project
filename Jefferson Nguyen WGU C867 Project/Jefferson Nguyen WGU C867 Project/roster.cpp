#include <iostream>
#include <sstream> 
#include <string>
#include "roster.h"
using namespace std;


Roster::Roster()
{
	
}


Roster::~Roster()
{
	for (int i = 0; i < NUM_OF_STUDENTS; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}


void Roster::addStudent(string studentInfo)
{
	string sID, sFName, sLName, sEmail;
	int sAge, sDOne, sDTwo, sDThree;
	degreeProgram tempProgram;
	
	string temp;
	
	int i = 0;
	
	
	for(int i = 0; i < NUM_OF_STUDENTS; i++)
	{
		stringstream ss(studentInfo);
		getline(ss, sID, ','); 
		getline(ss, sFName, ','); 
		getline(ss, sLName, ','); 
		getline(ss, sEmail, ','); 
		getline(ss, temp, ','); 
		sAge = stoi(temp); 
		getline(ss, temp, ','); 
		sDOne = stoi(temp); 
		getline(ss, temp, ',');
		sDTwo = stoi(temp); 
		getline(ss, temp, ','); 
		sDThree = stoi(temp); 

		getline(ss, temp, ','); 
		if (temp == "SECURITY")
		{
			tempProgram = degreeProgram::SECURITY;
		}
		else if (temp == "NETWORK")
		{
			tempProgram = degreeProgram::NETWORK;
		}
		else if (temp == "SOFTWARE")
		{
			tempProgram = degreeProgram::SOFTWARE;
		}
		else
		{
			cout << "No Degree Program" << endl;
		}
	}

	add(sID, sFName, sLName, sEmail, sAge, sDOne, sDTwo, sDThree, tempProgram); 
}


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degreeProgram theDegreeProgram)
{
	int theDays[THE_DAY_SIZE] = {daysInCourse1, daysInCourse2, daysInCourse3}; 
	classRosterArray[theIndex++] = new Student(studentID, firstName, lastName, emailAddress, age, theDays, theDegreeProgram);
}


void Roster::remove(string studentID)
{
	bool found = false; 
	
	for(int i = 0; i < NUM_OF_STUDENTS; i++)
	{
		if (classRosterArray[i] == NULL)
		{
			cout << "Student " << studentID << " was not found." << endl;
		}
		else if (studentID == classRosterArray[i]->getStudentIdNum()) 
		{
			classRosterArray[i] = NULL; 
			found = true; 
			cout << "Student " << studentID << " was removed." << endl;
		}
	}
}


void Roster::printAll()
{
	for(int i = 0; i < NUM_OF_STUDENTS; i++)
	{
		if (classRosterArray[i] != NULL)
		{
			classRosterArray[i]->Student::print();
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{
	
	for(int i = 0; i < NUM_OF_STUDENTS; i++)
	{
		if (classRosterArray[i]->getStudentIdNum() == studentID)
		{
			int avg = (classRosterArray[i]->getTheDays()[0] + classRosterArray[i]->getTheDays()[1] + classRosterArray[i]->getTheDays()[2]) / 3;
			cout << "Student " << studentID << " average number of days in all courses is " << avg << endl;
		}
	}

}


void Roster::printInvalidEmails()
{
	
	for(int i = 0; i < NUM_OF_STUDENTS; i++)
	{
		string tempEmail = classRosterArray[i]->getStudentEmailAddress();
		if (tempEmail.find('@') == string::npos || tempEmail.find(' ') != string::npos || tempEmail.find('.') == string::npos)
		{
			cout << classRosterArray[i]->getStudentIdNum() << ", your email is invalid." << endl;
		}
	}
}


void Roster::printByDegreeProgram(degreeProgram theDegreeProgram)
{
	for (int i = 0; i < NUM_OF_STUDENTS; i++)
	{
		if (classRosterArray[i] != NULL)
		{
			if (classRosterArray[i]->getTheDegreeProgram() == theDegreeProgram)
			{
				classRosterArray[i]->print();
			}
		}
		else
		{
			cout << "NO DEGREE INDICATED" << endl;
		}
		
	}

}