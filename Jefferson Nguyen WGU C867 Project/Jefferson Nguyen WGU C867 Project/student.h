#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

const static int THE_DAY_SIZE = 3; 


class Student
{
	
	
	private:
		string studentIdNum;
		string studentFirstName;
		string studentLastName;
		string studentEmailAddress;
		int studentAge;
		int days[THE_DAY_SIZE];
		degreeProgram theDegreeProgram;
	
	public:
		Student(); 
		Student(string theStudentIdNum, string theStudentFirstName, string theStudentLastName, string theStudentEmailAddress, int theStudentAge, int theDays[], degreeProgram degreeP); 
		~Student(); 

		
		friend ostream& operator<<(ostream& output, const degreeProgram& d);

		
		string getStudentIdNum() const; 
		string getStudentFirstName() const;
		string getStudentLastName() const; 
		string getStudentEmailAddress() const;
		int getStudentAge() const;
		int* getTheDays(); 
		degreeProgram getTheDegreeProgram() const;

		
		void setStudentIdNum(string theStudentIdNum);
		void setStudentFirstName(string theStudentFirstName);
		void setStudentLastName(string theStudentLastName);
		void setStudentEmailAddress(string theStudentEmailAddress);
		void setStudentAge(int theStudentAge);
		void setTheDays(int theDays[]);
		void setTheDegreeProgram(degreeProgram degreeP);

		

		void print();

	

};

#endif 
