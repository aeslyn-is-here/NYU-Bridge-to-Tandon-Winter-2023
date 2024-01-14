#include <iostream>
using namespace std;

int minInArray(int arr[], int arrSize);
void inputArray(int arr[], int arraySize);
void numIndex(int arr[], int arraySize, int minValue);
const int ARRAY_SIZE=20;

int main()
{
   int array[ARRAY_SIZE];
   
   cout<< "Please input " << ARRAY_SIZE << " integers seperated by a space: "<< endl;
   
   inputArray(array, ARRAY_SIZE);
   
   cout << "The minimum value is " << minInArray(array, ARRAY_SIZE) << " and it's located in the following indices: ";
   int minVal=minInArray(array, ARRAY_SIZE);
   numIndex(array, ARRAY_SIZE, minVal);
    
    
    return 0;
}

int minInArray(int arr[], int arrSize)
{
   int minVal = arr[0];
      for (int i = 1; i < arrSize; i++)
      {
         if (arr[i] < minVal)
         {
            minVal = arr[i];
         }
      }
      return minVal;
}

void inputArray(int arr[], int arraySize)
{
   for(int i=0; i< arraySize; i++)
   {
      cin >> arr[i];
   }
}
void numIndex(int arr[], int arraySize, int minValue)
{
   int min=minValue;
   for(int i=0; i<arraySize; i++)
   {
      if (min==arr[i])
         cout<< i << " ";
   }
}
