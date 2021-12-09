//Brennan Catalan
//12/7/2021
//CIS 1202 502

#include <iostream>
#include "Employee_C.h"
#include<string>

using namespace std;

int main()
{
    const int SIZE = 100;
    
    Employee_C empArray[SIZE];
    Employee_C* ptr = new Employee_C[SIZE]; //This pointer recieves the pointer returned by the fill_array() function
    bool arrayFilled = false;
    string file;
    
        try
        {



        ptr = Fill_Array(arrayFilled);
        arrayFilled = true;
        for (int i = 0; i < sizeof(*ptr); i++)
        {
            empArray[i] = *(ptr + i);


        }
        ptr = Fill_Array(arrayFilled); // arrayFilled has been passed as true, so the dynamic memory will be deleted and the function execution will cease early

         }
        
        
        catch (string null)
        {
            cout << null;
            return 0;
        }

        catch (bool memoryDeleted)// This catch contains no statements because it is simply used to exit the second iteration of the fill array function once the memory has been deleted
        {
            cout <<endl << "Dynamically Allocated memory deleted successfully..." << endl;
            
        }
    
        delete[] ptr; //Delete the dynamically allocated memory for the ptr in main.


        cout << endl << endl << "Please enter a name for the file: ";
        cin.ignore();
        getline(cin,file);

        cin.ignore();
        
        try
        {
            Extract_ID(file, empArray);
        }

        catch (string fileFailed)
        {
            cout <<endl << fileFailed;

            try
            {



                getline(cin, file);
                cin.ignore();
                Extract_ID(file, empArray);
            }


            catch (string fileFailed)
            {
                cout << "Error. Could not open file. Program ending...";
                return 0;
            }

        }
    
        
        
        int index = 0;
        int* indexPointer = &index;
        while (true)
        {
            
            int getID;
          

            cout <<endl << "Enter the ID number of the employee you wish to search for or enter 1234 to end the program: ";
            cin >> getID;


            if (getID ==1234)
                return 0;
            
            
            
            
            try
            {
                Find_Employee(file, indexPointer, getID);
            }
            catch (int found)
            {
                cout << endl << "Employee found" << endl << endl;
            }
                
             
            
            
            if(index==-1)
            cout <<endl << "Error. Erroneous ID# " <<getID <<". Employee not found." <<endl <<endl;
            
            else
            {
                
                
                empArray[index].Display_Employee(); 

            }
             
            
                
            

        }


}

