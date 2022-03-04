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
	int
		position = 0,
		tempValue = 0,
		steps = 0,
		comparisonCtr = 0,
		shifts = 0,
		totComparison = 0;

	for (int index = 1; index < arraySize; index++) {
		tempValue = arrayToSort[index];
		position = index - 1;
		comparisonCtr += 1;
		totComparison += comparisonCtr;
		++steps;

		cout << "Pass # " << steps << " - ";
		print(arrayToSort, arraySize);
		cout << " -> " << comparisonCtr << " comparisons, " << shifts << " shifts " << endl;
		while (position >= 0) {
			if (arrayToSort[position] > tempValue) {
				arrayToSort[position + 1] = arrayToSort[position];
				position--;
				shifts += 1;
			}
			else {
				break;
			}
			arrayToSort[position + 1] = tempValue;

		}
		
		
	}
	cout << endl
		<< "Passes: " << steps << endl
		<< "Comparisons: " << totComparison << endl
		<< "Shifts: " << shifts << endl;
	
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