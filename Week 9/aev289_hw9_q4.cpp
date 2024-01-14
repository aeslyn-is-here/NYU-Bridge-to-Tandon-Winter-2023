#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
void printArr(int arr[], int arrSize);
int main()
{
    const int ARRAY_SIZE=6;
    int arr[ARRAY_SIZE]={5, 2, 11, 7, 6, 4};
    
    cout<< "Original array: ";
    printArr(arr, ARRAY_SIZE);
    cout<<"Ordered array: ";
    oddsKeepEvensFlip(arr, ARRAY_SIZE);
    printArr(arr, ARRAY_SIZE);
    
    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize)
{
    int * new_arr= new int[arrSize];
    int start=0;
    int end=arrSize-1;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] % 2 == 0)
        {
            new_arr[end--]=arr[i];
        }
        else
        {
            new_arr[start++]=arr[i];
        }
    }
    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = new_arr[i];
    }

    delete [] new_arr;
}

void printArr(int arr[], int arrSize)
{
    for(int i=0; i<arrSize; i++)
    {
        cout<< arr[i] <<" ";
    }
    cout<< endl;
}
