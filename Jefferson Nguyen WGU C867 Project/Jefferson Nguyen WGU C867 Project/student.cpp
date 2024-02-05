#include <iostream>
#include "student.h"
#include <string>
#include <iomanip> 

using namespace std;


Student::Student()
{
	studentIdNum = "A0";
	studentFirstName = "John";
	studentLastName = "Doe";
	studentEmailAddress = "john.doe@email.com";
	studentAge = 24;
	for (int i = 0; i < THE_DAY_SIZE; i++) 
	{
		days[i] = i + 1; 
	}
	theDegreeProgram = degreeProgram::SECURITY;
}


Student::Student(string theStudentIdNum, string theStudentFirstName, string theStudentLastName, string theStudentEmailAddress, int theStudentAge, int theDays[], degreeProgram degreeP)
{
	studentIdNum = theStudentIdNum;
	studentFirstName = theStudentFirstName;
	studentLastName = theStudentLastName;
	studentEmailAddress = theStudentEmailAddress;
	studentAge = theStudentAge;
	for (int i = 0; i < THE_DAY_SIZE; i++) 
	{
		days[i] = theDays[i];
	}
	theDegreeProgram = degreeP;
}


Student::~Student()
{

}


ostream& operator<<(ostream& output, const degreeProgram& dP)
{
	switch (dP)
	{
	case SECURITY:
		output << "SECURITY";
		break;
	case NETWORK:
		output << "NETWORK";
		break;
	case SOFTWARE:
		output << "SOFTWARE";
		break;
	}
	return output;
}


string Student::getStudentIdNum() const
{
	return studentIdNum;
}


string Student::getStudentFirstName() const
{
	return studentFirstName;
}


string Student::getStudentLastName() const
{
	return studentLastName;
}


string Student::getStudentEmailAddress() const
{
	return studentEmailAddress;
}


int Student::getStudentAge() const
{
	
	return studentAge;
}


int* Student::getTheDays()
{
	return days;
}

degreeProgram Student::getTheDegreeProgram() const
{
	return theDegreeProgram;
}


void Student::setStudentIdNum(string theStudentIdNum)
{
	studentIdNum = theStudentIdNum;
}


void Student::setStudentFirstName(string theStudentFirstName)
{
	studentFirstName = theStudentFirstName;
}


void Student::setStudentLastName(string theStudentLastName)
{
	studentLastName = theStudentLastName;
}


void Student::setStudentEmailAddress(string theStudentEmailAddress)
{
	studentEmailAddress = theStudentEmailAddress;
}


void Student::setStudentAge(int theStudentAge)
{
	studentAge = theStudentAge;
}


void Student::setTheDays(int theDays[])
{
	for (int i = 0; i < THE_DAY_SIZE; i++)
	{
		days[i] = theDays[i];
	}
}


void Student::setTheDegreeProgram(degreeProgram degreeP)
{
	theDegreeProgram = degreeP;
}


void Student::print()
{
	cout << "Student ID\t" << "First Name\t" << "Last Name\t" << "Email\t\t\t" << " " << "Age\t" << "Days in Course\t" << "Degree Program" << endl;
	cout << setw(16) << left << getStudentIdNum();
	cout << setw(16) << left << getStudentFirstName();
	cout << setw(16) << left << getStudentLastName();
	cout << setw(25) << left << getStudentEmailAddress();
	cout << setw(7) << left << getStudentAge();

	int* theDaysC = getTheDays();
	for (int i = 0; i < THE_DAY_SIZE; i++)
	{
		cout << theDaysC[i] << setw(6) << right;
	}
	
	cout << setw(10) << getTheDegreeProgram() << endl;

}