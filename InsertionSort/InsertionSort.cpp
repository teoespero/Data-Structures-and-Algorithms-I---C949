////////////////////////////////////////////////////////////////////////////////
// InsertionSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  Teodulfo Espero
//  BS Cloud and Systems Administration
//  BS Software Development
//  Western Governors University
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// function for printing our sorted array
void print(int* theArray, int theSize) {

	for (int i = 0; i < theSize; ++i) {
		cout << theArray[i];
		if (i < theSize - 1)
			cout << ", ";
	}
}

////////////////////////////////////////////////////////////////////////////////
// insertion sort function implementation
int* insertionSort(int arrayToSort[], int arraySize) {

	// declare and initialize our variables
	int
		position = 0,
		tempValue = 0,
		steps = 0,
		comparisonCtr = 0,
		shifts = 0,
		totComparison = 0;


	// Each round of this loop represents a pass-through
	for (int index = 1; index < arraySize; index++) {
		
		// we save the value we’re “removing” in a variable
		// called temp_value
		tempValue = arrayToSort[index];

		// position will represent each value we
		// compare against the temp_value
		// this position will keep moving leftward
		// as we compare each value to the temp_value
		position = index - 1;
		
		// get the stats for our program
		// the steps, the passes, and comparison count
		comparisonCtr += 1;
		totComparison += comparisonCtr;
		++steps;

		// print the current state of the array
		// for every pass
		cout << "Pass # " << steps << " - ";
		print(arrayToSort, arraySize);
		cout << " -> " << comparisonCtr << " comparisons, " << shifts << " shifts " << endl;

		// h runs as long as position is greater or
		// equal to 0
		while (position >= 0) {

			// check whether the value at position is greater 
			// the temp value
			if (arrayToSort[position] > tempValue) {

				// if it is, then shift the values to the right
				arrayToSort[position + 1] = arrayToSort[position];

				// decrement position by 1 to compare the next 
				// left value against the temp_value
				position--;

				// we also need to know how many shifts
				// are done
				shifts += 1;
			}
			else {
				break;
			}

			// the final step of each pass-through is moving 
			// the temp_value into the gap
			arrayToSort[position + 1] = tempValue;

		}
		
		
	}

	// print out our stats
	cout << endl
		<< "Passes: " << steps << endl
		<< "Comparisons: " << totComparison << endl
		<< "Shifts: " << shifts << endl;
	

	// After all pass-throughs have been completed, 
	// we return the sorted array
	return arrayToSort;
}

int main(){
	// declare an array of numbers
	int myArray[] = { 4,2,7,1,3 };

	// determine our array size
	int len = (sizeof(myArray) / sizeof(myArray[0]));

	// say "HI!"
	cout << endl << "INSERTION SORT" << endl << endl;

	// initial array (unsorted)
	cout << "Unsorted values: ";
	print(myArray, len);
	cout << endl << "-------------------------------" << endl;

	// pass the array to our selection sort function
	cout << endl << "Sorting..." << endl;
	int* myPtr = insertionSort(myArray, len);

	// print out the sorted array
	cout << endl << "-------------------------------" << endl << "Sorted values: ";
	print(myPtr, len);
	cout << endl;

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
// terminate and exit