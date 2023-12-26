#include<iostream>
using namespace std;

void swap(int min,int ctr, int arr[])
{
    int temp;
    temp = arr[min] ;
    arr[min] = arr[ctr];
    arr[ctr] = temp;
}

void selectionSort(int array[], int size)
{
    int indexTraveler = 0;
    int minIndex = 0;

    int firstIndex = array[minIndex];
    for(int counter = 0 ; counter < size -1 ; counter++)
    {
        minIndex = counter;
        for(indexTraveler = counter + 1 ; indexTraveler < size ; indexTraveler++)
        {
            if(array[minIndex] > array[indexTraveler])
            {
                minIndex = indexTraveler;
            }
        }
            swap(minIndex,counter,array);
    }
}
