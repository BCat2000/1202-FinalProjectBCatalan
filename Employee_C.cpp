#include "Employee_C.h"
#include <string>
#include<iostream>
#include <fstream>


using namespace std;

int Employee_C::totalSalaries = 0;

Employee_C::Employee_C()
{
	 employeeName[0] = 'a';
	 idNumber = 0;
	 empSalary = 0;
	 empGender = '.';



}

void Employee_C::setName(string name)
{
	strcpy_s(employeeName, name.c_str());
}


void  Employee_C::setID(int id)
{
	idNumber = id;
}
void Employee_C::setSalary(int salary)
{

	totalSalaries -= empSalary; // This works because salaries are set to 0 by the constructor.
	empSalary = salary;
	totalSalaries += empSalary;


}
void Employee_C::setGender(char gender)
{
	empGender = toupper(gender);
}

char Employee_C::getName(int k) const
{
	return employeeName[k];// Because the name is stored as a c string and not a string, the name cannot simply be returned.
						  // This returns one character in the array at a time and the function call is looped according to the size of the name in the array.
}
int Employee_C::getID() const
{
	return idNumber;
}
int  Employee_C::getSalary() const
{
	return empSalary;
}
char Employee_C::getGender() const
{
	return empGender;
}





Employee_C* Fill_Array(bool arrayFilled)
{
	

	const int ARRAY_SIZE = 100;
	int index = 1, indexTwo=0;
	string nullPointer = "Error. Memory could not be allocated. Exiting program...";
	char choice = 'Y', tempGender;
	bool memoryDeleted = true;

	int tempID, tempSal;
	
	string tempName;




	Employee_C* empArray = new Employee_C[ARRAY_SIZE];
	if (arrayFilled) // This is used to delete the dynamically allocated array once the array has been moved into main().
	{				// The function is designed to be called twice, only the second time arrayFilled will be true, so this will execute
					// which causes the dynamically allocated memory to be deleted and then a throw is used to exit the function.
		delete[] empArray;
		throw memoryDeleted; 

	}

	if (empArray == nullptr)//This checks if the allocation has failed
		throw nullPointer;

	cout << "Please begin entering employee information..." << endl << endl;
	
	while (indexTwo <= sizeof(ARRAY_SIZE) && choice == 'y' || indexTwo <= sizeof(ARRAY_SIZE) && choice == 'Y')
	{
		
		cin.ignore();
		Employee_C tempEmployee;

		

		cout << endl << "Please enter the name for employee #" << index <<": ";
	
		getline(cin, tempName);
		cin.ignore();
		tempEmployee.setName(tempName);
		

		cout << endl << endl <<"Please enter the ID for employee #" << index << ": ";
		cin >> tempID;
		tempEmployee.setID(tempID);

		cout << endl << endl << "Please enter the salary for employee #" << index << ": $";
		cin >> tempSal;
		tempEmployee.setSalary(tempSal);

		cout << endl << endl << "Please enter the gender for employee #" << index << ": ";
		cin >> tempGender;
		tempEmployee.setGender(tempGender);



		empArray[indexTwo] = tempEmployee;

		indexTwo++;
		index++;

		cout << endl << endl << "Would you like to enter another employee? (Y/N) " ;
		cin >> choice;


		
	}

	
	return empArray;
}


void Extract_ID(string fileName, Employee_C empArray[])
{
	string textFile = (fileName)+".txt";
	fstream outFile;
	
	

	outFile.open(textFile.c_str(), ios::out | ios::binary);
	

	if (!outFile)
	{
		string fileFailed = "Error. Could not open file. Please re-enter the filename and try again... ";
		throw fileFailed;
	}

	for (int i = 0; empArray[i].getSalary() != 0;i++) // This for loop uses the salary of the employee stored in the current location of the array
	{												//Because the constructor sets the salary at 0 and an employee will not have a salary of $0, this value can be used to check if there is a valid object in the array position
		outFile<< empArray[i].getID() <<'\n';

	}

	outFile.close();



}



void Find_Employee(string fileName, int* index, int ID)
{
	ifstream inFile;
	bool found = false;
	
	
	

	int tempID;

	string textFile = fileName + ".txt";
	inFile.open(textFile.c_str(), ios::in | ios::binary);

	if(!inFile)
	{
		string fileFailed = "Error. Could not open file. Please re-enter the filename and try again... ";
		cout << fileFailed;
	}


	inFile.clear();

	int indexTwo = 0;
	while (!inFile.eof())
	{
		int empFound = 1;;
		
		

		inFile >> tempID;

		

		if (tempID == ID)
		{
			found = true;
			
			
			
			*index = indexTwo; // The value pointed to by the pointer that points to the index int in main() is set to the value of indexTwo 
			throw empFound; // This throw is used to end the loop in the case that the ID has been found
		}

		
		
		

		indexTwo++;
		
	}
	
	if (!found)
	{
		*index = -1;
		
	}
	inFile.close();
}



void Employee_C::Display_Employee()
{
	
	cout << "Employee ID: " << idNumber << endl;
	cout << "Employee Name: " << employeeName <<endl;
	cout << "Employee Salary: " << empSalary << endl;
	cout << "Employee Gender: " << empGender << endl;
	cout << "Total Salaries: " << totalSalaries << endl;



}