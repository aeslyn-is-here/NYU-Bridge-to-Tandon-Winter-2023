#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main()
{
    const int ARRSIZE= 4;
    int arr[ARRSIZE]={2,-1, 3, 10};
    cout<< "Array: ";
    printArray(arr, ARRSIZE);
    
    cout<< "Sum of squares: ";
    cout<< sumOfSquares(arr, ARRSIZE)<< endl;
    
    cout<<"Is Sorted: ";
    if(isSorted(arr, ARRSIZE))
    {
        cout<< "True";
    }
    else
    {
        cout<< "False";
    }
    cout<<endl;
    return 0;
}
int sumOfSquares(int arr[], int arrSize)
{
    if (arrSize == 1)
    {
        return arr[0] * arr[0];
    } else
    {
        int index = arr[arrSize - 1];

        return sumOfSquares(arr, arrSize - 1) + index * index;
    }
}
bool isSorted(int arr[], int arrSize)
{
    if(arrSize==1)
    {
        return true;
    }
    else
    {
        int index = arr[arrSize - 1];
        int prev = arr[arrSize - 2];
        return isSorted(arr, arrSize - 1) && (prev<= index);
    }
}
void printArray(int arr[], int arrSize)
{
    cout << "[";

    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i];

        if (i != arrSize - 1)
        {
            cout << ", ";
        }
    }

    cout<< "]"<< endl;
}


