// LabListRandom
// CSC 2430 Lab Assignment
// Written by:
// Date:

#include <iostream>
#include <iomanip>
#include <cstddef>
#include <limits>
using namespace std;

#include "SortedLabList.h"
#include "LabListP.h"

void printListClass(char listname[], const ListClass& lst)
{
	cout << listname << ": length=" << lst.getLength() << " items" << endl;

	int numitems = lst.getLength();
	for (int i = 1; i <= numitems; ++i)
	{
		int val;
		if (lst.retrieve(i, val))
			cout << setw(3) << i << ": " << setw(5) << val << endl;
		else
			cout << "Cannot retrieve item from position " << i << endl;
	}
	cout << endl;
}

void printSortedListClass(char listname[], const SortedListClass& lst)
{
    cout << listname << ": length=" << lst.getLength() << " items" << endl;
    
    int numitems = lst.getLength();
    for (int i = 1; i <= numitems; ++i)
    {
        int val;
        if (lst.retrieve(i, val))
            cout << setw(3) << i << ": " << setw(5) << val << endl;
        else
            cout << "Cannot retrieve item from position " << i << endl;
    }
    cout << endl;
}

void comparingLists(char listname[], char sortedname[], const ListClass& ul, const SortedListClass ol)
{
    cout << "Correlation between locations of items in " << listname << " and " << sortedname << endl;
    
    int numitems = ul.getLength();
    for (int i = 1; i <= numitems; ++i) {
        int val;
        if (ul.retrieve(i, val)) {
            cout << listname << "[" << i << "] = " << val << " --> " << sortedname << "[" << ol.find(val) << "]" << endl;
        }
    }
}

int main()
{
	/////////////////////////////////////////////////
	// setup
	const int N = 10;			// number of items, used only to create initial list of values
	const int RANGE = 32768;	// value range. Set to INT_MAX for a list of values from 0 .. 32767

	// Prepare random number generator with initial seed value
	//    and discard the first few data items in the sequence
	srand(3);
	for (int i = 0; i < 10; ++i)
		rand();

	/////////////////////////////////////////////////
	// Greeting
	cout << "Linked List Lab: Implemented by Jaryd Remillard" << endl;
	cout << "Randomly generate list of " << N << " values in range 0-" << RANGE - 1 <<
			" and convert into a sorted list" << endl << endl;

	/////////////////////////////////////////////////
	// Create initial "by position" data value list
	ListClass listbyposition;
    SortedListClass firstsortedlist;

	for (int i = 1; i <= N; ++i)
	{
		int val = rand() % RANGE;		// produce next random number value
		listbyposition.insert(i, val);  // Put val into list at position i
	}

	// Output initial data list
	printListClass("listbyposition", listbyposition);
    
    for (int i = 1; i <= N; ++i) {
        int val;
        if (listbyposition.retrieve(i, val)) {
            firstsortedlist.insert(val);
        }
    }
    
    printSortedListClass("firstsortedlist", firstsortedlist);

    comparingLists("listbyposition", "firstsortedlist", listbyposition, firstsortedlist);
    
    SortedListClass secondsortedlist;
    secondsortedlist = firstsortedlist;
    
    firstsortedlist.remove(1);
    firstsortedlist.remove(1);
    
    int value = -10;
    secondsortedlist.insert(value);
    
    printSortedListClass("\nfirstsortedlist", firstsortedlist);
    printSortedListClass("secondsortedlist", secondsortedlist);
    
	return(0);
}
