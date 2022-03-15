// Vec.cc
#include "Vec.h"
#include <algorithm>
#include <iostream>
using namespace std;

Vec::Vec()
{
	array_current_size = array_limit = 0;
	pointer_to_data = 0;
}

// Constructor
Vec::Vec(int a)
{
	array_current_size = 0;
	array_limit = a;

	// Allocate new memory for array.
	pointer_to_data = new double[array_limit];

}
// Overloading the copy constructor.
Vec::Vec(const Vec& vec_to_copy)
{
	array_current_size = vec_to_copy.array_current_size;
	array_limit = vec_to_copy.array_limit;

	// Allocate new memory for array.
	pointer_to_data = new double[array_limit];

	// Copy data across.
	for (int i = 0; i != array_current_size; ++i)
	{
		pointer_to_data[i] = vec_to_copy.pointer_to_data[i];
	}
}
// Destructor
Vec::~Vec()
{
	// Free array memory
	delete[] pointer_to_data;
	// Set pointer to null
	pointer_to_data = 0;
	array_current_size = array_limit = 0;
}
// Overloading the assignment operator.
Vec& Vec::operator=(const Vec& rhs)
{
	// Check for self-assignment.
	if (&rhs != this) {
		// Free lhs array memory.
		delete[] pointer_to_data;

		// Allocate new memory for lhs array.
		array_current_size = rhs.array_current_size;
		array_limit = rhs.array_limit;
		pointer_to_data = new double[array_limit];

		// Copy rhs data across.
		for (int i = 0; i != array_current_size; ++i) {
			pointer_to_data[i] = rhs.pointer_to_data[i];
		}
	}

	return *this;
}
// Overloading the index operator
double& Vec::operator[](int i)
{
	return pointer_to_data[i];
}

// Method to dynamically increase* the size of an array at runtime. 
//								*Create new array with more space and copy old array contents to it. 
void Vec::grow()
{
	/*
	* Account for zero and negative array_limits (limit of elements allowed in current array)
	*/
	//is the array size limit negative or zero
	if (array_limit <= 0)
	{
		//if so, delete allocated memory
		delete[] pointer_to_data;

		//set the array size limit to a value > 0
		array_limit = 1;

		//Initialise array with the initialised size limit in memory
		pointer_to_data = new double[array_limit];
	}
	//is the array size limit > zero
	else
	{
		//create a storage array to hold data member values in memory
		double* temp_array = new double[array_limit];

		//double our array size limit
		array_limit *= 2;

		//iterate through our temporary array		
		for (int i = 0; i < get_current_size(); i++)
		{
			//assign values of our current array to the temporary array
			temp_array[i] = pointer_to_data[i];
		}

		//remove pointer_to_data from memory
		delete[] pointer_to_data;

		//create an array with new size limits in memory
		pointer_to_data = new double[array_limit];

		//iterate through our new array
		for (int i = 0; i < get_current_size(); i++)
		{
			//assign values of our temporary array to our new array
			pointer_to_data[i] = temp_array[i];
		}

		//remove temp_array from memory
		delete[] temp_array;
	}
}

//Method to "push" a variable ('a') to the "back" of an array
void Vec::push_back(const double& a)
{
	//if current array is full, call grow() to allow additional elements to be added to the array
	if (array_current_size >= array_limit)
		grow();

	//increment array_current_size
	array_current_size++;

	//append 'a' onto end of array
	pointer_to_data[array_current_size - 1] = a;
}