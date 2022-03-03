////////////////////////////////////////////////////////////////////////////////
//  BubbleSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  Teodulfo Espero
//  BS Cloud and Systems Administration
//  BS Software Development
//  Western Governors University
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


////////////////////////////////////////////////////////////////////////////////
// bubble sort function implementation
int* bubble_sort(int toBeSorted[], int listSize) {
	int unsorted_until_index = listSize - 1;
	int temp=0;
	bool sorted = false;

	while (!sorted) {
		sorted = true;
		for (int i = 0; i < unsorted_until_index; i++) {

			// compare two values (prev and next)
			// if the previous is greater than the next value
			// swap them
			if (toBeSorted[i] > toBeSorted[i + 1]) {
				temp = toBeSorted[i];
				toBeSorted[i] = toBeSorted[i + 1];
				toBeSorted[i + 1] = temp;
				sorted = false;
			}
		}
	}

	// return the sorted array
	return toBeSorted;

}

int main(){
	int myArray[] = {3,2,4,1,8,5,6,9,7};
	int len = (sizeof(myArray) / sizeof(myArray[0]));

	int* myPtr = bubble_sort(myArray, len);

	for (int i = 0; i < 9; ++i) {
		cout << myPtr[i];
		if (i < len -1) 
			cout << ", ";
	}

	return 0;
}

