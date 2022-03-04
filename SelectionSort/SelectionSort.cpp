////////////////////////////////////////////////////////////////////////////////
// SelectionSort.cpp : This file contains the 'main' function. 
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
// selection sort function implementation
int* selectionSort(int arrayToSort[], int arraySize) {
	int lowestNumberIndex = 0;
	int temp, steps = 0;
	int comparisonCtr = 0;

	// go through then list and compare the values
	// to get the lowest value's index
	for (int ptr = 0; ptr < arraySize - 1; ptr++) {

		// set the current index as the lowest value
		// this changes when a new value is found
		lowestNumberIndex = ptr;
		++steps;
		cout << "Pass # " << steps << " - ";
		print(arrayToSort, arraySize);
		cout << " -> " << (arraySize - 1) - ptr << " comparisons";
		comparisonCtr = comparisonCtr + ((arraySize - 1) - ptr);
		cout << endl;
		for (int nextPtr = ptr + 1; nextPtr < arraySize; nextPtr++) {

			// show the steps, and the resulting array
			if (arrayToSort[nextPtr] < arrayToSort[lowestNumberIndex])
				lowestNumberIndex = nextPtr;
		}

		// after each pass, if a lower value is found, that 
		// value is moved to the unsorted element
		if (lowestNumberIndex != ptr) {
			temp = arrayToSort[ptr];
			arrayToSort[ptr] = arrayToSort[lowestNumberIndex];
			arrayToSort[lowestNumberIndex] = temp;
		}
	}

	// once we are done doing the pass throughs
	// the sorted arrays are sent back to the 
	// main program

	cout << endl << comparisonCtr << " Total comparisons performed..." << endl;
	return arrayToSort;
}




////////////////////////////////////////////////////////////////////////////////
// main program
int main(){  
	// declare an array of numbers
	int myArray[] = {4,2,7,1,3 };

	// determine our array size
	int len = (sizeof(myArray) / sizeof(myArray[0]));

	// say "HI!"
	cout << endl << "SELECTION SORT" << endl << endl;

	// initial array (unsorted)
	cout << "Unsorted values: ";
	print(myArray, len);
	cout << endl << "-------------------------------" << endl;

	// pass the array to our selection sort function
	cout << endl << "Sorting..." << endl;
	int* myPtr = selectionSort(myArray, len);

	// print out the sorted array
	cout << endl << "-------------------------------" << endl << "Sorted values: ";
	print(myPtr, len);
	cout << endl;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////
// terminate and exit