////////////////////////////////////////////////////////////////////////////////
//  BinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  Teodulfo Espero
//  BS Cloud and Systems Administration
//  BS Software Development
//  Western Governors University
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


int binary_search(int arr[], int searchValue, int arrSize) {
	
	int
		lowerBound = 0,
		upperBound = 0,
		midPoint = 0,
		valueAtMidPoint = 0;

	////////////////////////////////////////////////////////////////////////////
	// First, we establish the lowerand upper bounds of where the value
	// we're searching for can be. To start, the lower bound is the first
	// value in the array, while the upper bound is the last value :

	upperBound = arrSize - 1;

	////////////////////////////////////////////////////////////////////////////
	// We begin a loop in which we keep inspecting the middlemost value
	// between the upperand lower bounds :

	while (lowerBound <= upperBound) {

		////////////////////////////////////////////////////////////////////////
		//  We find the midpoint between the upperand lower bounds :
		// (We don't have to worry about the result being a non-integer
		// since in Ruby, the result of division of integers will always
		// be rounded down to the nearest integer.)

		midPoint = (upperBound + lowerBound) / 2;

		// We inspect the value at the midpoint :
		valueAtMidPoint = arr[midPoint];

		// If the value at the midpoint is the one we're looking for, we're done.
		// If not, we change the lower or upper bound based on whether we need
		// to guess higher or lower:

		if (searchValue == valueAtMidPoint)
			return midPoint;
		if (searchValue < valueAtMidPoint)
			upperBound = midPoint - 1;
		if (searchValue > valueAtMidPoint)
			lowerBound = midPoint + 1;
	}

	// If we've narrowed the bounds until they've reached each other, that
	// means that the value we're searching for is not contained within
	// this array:

	return -1;
}


int main(){
	//////////////////////////////////////////////////////////////////////////
	// implementation

	int whatToLookFor = 0;
	int myArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 50, 78, 99 };
	int position;

	cout << "Enter a number to look for: ";
	cin >> whatToLookFor;

	position = binary_search(myArray, whatToLookFor, (sizeof(myArray)/ sizeof(myArray[0])));

	if (position >= 0)
		cout << "Number found in index: " << position << endl;
	else
		cout << "Number is not in our list... " << endl;

	return 0;
}

