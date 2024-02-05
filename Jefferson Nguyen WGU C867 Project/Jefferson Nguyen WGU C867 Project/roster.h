#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include "student.h"
#include <string>
using namespace std;

const static int NUM_OF_STUDENTS = 5;

class Roster
{
	private:
		int theIndex = 0;
		
	public:
		Roster(); 
		~Roster(); 
		Student* classRosterArray[NUM_OF_STUDENTS]; 
		void addStudent(string studentInfo);
		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degreeProgram theDegreeProgram);
		void remove(string studentID);
		void printAll();
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(degreeProgram theDegreeProgram);
};

#endif 

