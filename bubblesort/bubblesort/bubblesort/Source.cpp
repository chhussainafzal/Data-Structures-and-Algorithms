#include"Sort.h"
#include<iostream>
#define size 7
using namespace std;

Sort::Sort() {
	int arr[size];
}
void Sort::PrintArray()
{
	for (int i = 0;i < 7;i++)
	{
		cout << "Enter the element of Array: ";
		cin >> arr[i];
	}	
}


void Sort::BubbleSort()
{
	int m = 0;
	for (int i = 0;i < size;i++)
	{
		for (int j = i + 1;j < size;j++)
		{
			if (arr[i] > arr[j]) {
				m = arr[j];
				arr[j] = arr[i];
				arr[i] = m;
			}
		}
	}
}

void Sort::SortedArray() {
	BubbleSort();
	cout << endl << "The sorted Array is shown as" << endl;
	for (int i = 0;i < size;i++)
	{
		cout << arr[i] << " ";
	}
}
