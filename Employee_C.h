
#ifndef H
#define H
#pragma once
#include <string>
using namespace std;

const int ARRAY_SIZE=75;

class Employee_C
{
private:
	char employeeName[ARRAY_SIZE];
	int idNumber;
	int empSalary;
	char empGender;
	static int totalSalaries;

public:
	Employee_C();

	void setName(string name);
	void setID(int id);
	void setSalary(int salary);
	void setGender(char gender);

	char getName(int k) const;
	int getID( ) const;
	int getSalary( ) const;
	char getGender( ) const;
	void Display_Employee();

};

Employee_C* Fill_Array(bool arrayFilled);

void Extract_ID(string fileName, Employee_C empArray[]);

void Find_Employee(string fileName, int* index, int ID);





















#endif // !H