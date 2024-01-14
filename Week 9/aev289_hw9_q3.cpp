#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize,int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize,int** outPosArrPtr, int* outPosArrSizePtr);
void printArr(int arr[], int arrSize);

int main()
{
    const int ARR_SIZE=5;
    int arr[ARR_SIZE]={-1, 2, -3, 4, -5};
    
    cout<< "Startign array: "<< endl;
    printArr(arr,ARR_SIZE);
    
    int posNum1Size;
    int* posNum1= getPosNums1(arr,ARR_SIZE, posNum1Size);
    cout<< "getPosNum1: ";
    printArr(posNum1,posNum1Size);
    cout<< endl;
    
    int posNum2Size;
    int* posNum2 = getPosNums2(arr, ARR_SIZE, &posNum2Size);
    
    cout<<"getPosNums2: ";
    printArr(posNum1, posNum2Size);
    cout<< endl;
    
    int posNums3Size;
    int* posNums3= nullptr;
    
    getPosNums3(arr, ARR_SIZE, posNums3, posNums3Size);
    cout<<"getPosNum3: ";
    printArr(posNums3, posNums3Size);
    cout<< endl;
    
    int posNum4Size;
    int*posNum4= nullptr;
    
    getPosNums4(arr, ARR_SIZE, &posNum4, &posNum4Size);
    cout<<"getPosNum4: ";
    printArr(posNum4, posNum4Size);
    cout<<endl;
    
    delete [] posNum1;
    delete [] posNum2;
    delete [] posNums3;
    delete [] posNum4;
    
    return 0;
}

void printArr(int arr[], int arrSize)
{
    for(int i=0; i<arrSize; i++)
    {
        cout<< arr[i] <<" ";
    }
    cout<< endl;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize)
{
    int posCount=0;
    int*pos_arr=new int [arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            pos_arr[posCount++] = arr[i];
        }
    }

   outPosArrSize = posCount;

    return pos_arr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr)
{
    int posCount=0;
    int*pos_arr=new int [arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            pos_arr[posCount++] = arr[i];
        }
    }

   *outPosArrSizePtr= posCount;
    return pos_arr;
}

void getPosNums3(int* arr, int arrSize,int*& outPosArr, int& outPosArrSize)
{
    int posCount=0;
    int*pos_arr=new int [arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            pos_arr[posCount++] = arr[i];
        }
    }

   outPosArrSize = posCount;
    outPosArr=pos_arr;

}
void getPosNums4(int* arr, int arrSize,int** outPosArrPtr, int* outPosArrSizePtr)
{
    int posCount=0;
    int*pos_arr=new int[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            pos_arr[posCount++] = arr[i];
        }
    }
    *outPosArrSizePtr=posCount;
    *outPosArrPtr=pos_arr;
    
}
