#include<iostream>
using namespace std;


void insertionSort(int arr[], int size) 
{
	int firstIndex;
	int indexValue;
	for (int counter = 1; counter < size ; counter++) 
	{
		indexValue = arr[counter];//4
		firstIndex = counter - 1;//0
		while (firstIndex >= 0 && indexValue < arr[firstIndex])
		{
			arr[firstIndex+1] = arr[firstIndex];
				firstIndex--;
		}
		arr[firstIndex+1] = indexValue;
	}
}
