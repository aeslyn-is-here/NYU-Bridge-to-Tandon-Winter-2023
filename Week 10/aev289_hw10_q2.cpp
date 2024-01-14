#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main()
{
    const int ARR_SIZE=6;
    int og_arr[ARR_SIZE]= {3, 1, 3, 0, 6, 4};
    int resArrSize;
    
    cout<< "Original Array: "<< endl;
    cout << "[";

       for (int i = 0; i < ARR_SIZE; i++)
       {
           cout << og_arr[i];
           if (i != ARR_SIZE - 1)
           {
               cout << ", ";
           }
       }
    cout<< "] "<< endl;
    
    int* resArr= findMissing(og_arr, ARR_SIZE, resArrSize);
    
    cout<< "Missing Array: "<< endl;
    cout<<"[";
    for (int i = 0; i < resArrSize; i++)
    {
        cout << resArr[i];
        if (i != resArrSize - 1)
        {
            cout << ", ";
        }
    }
    cout<< "] "<< endl;
    
    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize)
{
    int* counter_arr= new int[n+1];
    int count=0;
    
    for(int i=0; i<n; i++)
    {
        counter_arr[arr[i]]++;
            
    }
    int* missing_arr = new int[n];
    for (int i = 0; i < n + 1; i++)
    {
        if (counter_arr[i] == 0)
        {
            missing_arr[count++] = i;
        }
    }
    resArrSize=count;
    return missing_arr;
    
}
