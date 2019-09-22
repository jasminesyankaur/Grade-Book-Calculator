#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>													//Headers needed for code to work
#include "student.h"
#include "bubble.h"
#include <fstream>
using namespace std;

struct classStats													//Struct that holds variables mean, min, max, median and name 
{
float mean;
float min;
float max;
float median;
char *name;
};

int main()
{
  classStats var;													//Variable of classStats called var
  student *array[19]; 													//array of 19 student pointers
  char cse[9];														//c-string to hold first line from "grades" file (CSCE1040)
  ifstream in_str;													//input stream to read from grades file
  float sum = 0;													//variable sum set equal to 0 to compute sum
  float total = 0;													//variable total set equal to 0 to compute total sum of all students grades
	
  in_str.open("grades");												//opening file grades

  in_str >> cse;													//reading in c string and storing for later

	cout.setf(ios::fixed);
        cout.setf(ios::showpoint);											//setting precision to 2
        cout.precision(2);
	

  for(int i = 0; i < 19; i++)												//for loop to access every index in array
  {
	array[i] = (student *)malloc(sizeof(student));									//using malloc to allocate space for each student pointer in the array
	array[i]->first = (char*)malloc(sizeof(char)*10);								//using malloc to allocate space for the char pointer (first name) 
	array[i]->last = (char*)malloc(sizeof(char)*10);								//using malloc to allocate space for the char pointer (last name)

	in_str >> array[i]->first; 
	in_str >> array[i]->last; 
	in_str >> array[i]->exam1; 											//reading in data from grades file
	in_str >> array[i]->exam2; 
	in_str >> array[i]->exam3;

	sum = array[i]->exam1 + array[i]->exam2 + array[i]->exam3;							//computing sum of student's exam grades
	array[i]->mean = (sum)/3;											//using that sum to compute avg
	total += array[i]->mean;											//getting total sum of all students grades to find mean later
  }
  bubble(array, 19);													//using bubble function to sort through array

  var.mean = total/19;													//computing the total mean of all students and saving it in classStats variable
  var.min = array[0]->mean;												//assigning the classStats varibale to the first index to represent minimum
  var.max = array[18]->mean;												//assigning the classStats variable to the last index to represent the maximum
  var.median = array[9]->mean;												//assigning the classStats variable to the middle index to represent the median

  cout << "123456789012345678901234567890123456789012345678901234567890" << endl;					//displaying line of digits from instructions
  cout << cse << " MEAN: " << var.mean << " MIN: " << var.min << " MAX: " << var.max << " MEDIAN: " << var.median << endl;		//displaying classStats

  for(int i = 0; i < 19; i++)												//using for loop to access each index of array
  {
	cout << array[i]->first << "       " << array[i]->last << "       " << array[i]->mean << endl;			//displaying each students data
  }
 

  in_str.close();													//closing file
										//PROGRAM COMPLETE
  return 0;
}
