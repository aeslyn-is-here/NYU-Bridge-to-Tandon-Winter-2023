#include <iostream>
#include <vector>
using namespace std;

vector<int> findMinMax(vector<int> fullUnsortedVector, int& min, int& max);
void divideAndConquer(vector<int> halfUnsortedVector, int& min, int& max);


int main(){
    vector<int> vectorSorted;
    vector<int> unsortedVector = {3, 7, 27, 8, 4679, -382, 28, 302, 24, 492, 384, 93, 999, 37, 5, 45, 345, 13, 39}; //length=19 
    // vector<int> unsortedVector={2,8,6,5};
    // vector<int> unsortedVector = {26, 6};
    // vector<int> unsortedVector = {4};
    // vector<int> unsortedVector = {4, 5, 235, 12, 5,2, 1235, 63, -29, 1293, -492, 942};
    int min=unsortedVector[0];
    int max=unsortedVector[0];

    vectorSorted = findMinMax(unsortedVector, min, max);
    cout<<"Min = "<<vectorSorted[0]<<endl;  
    cout<<"Max = "<<vectorSorted[1]<<endl;
    cout<<endl;

    return 0;
}

vector<int> findMinMax(vector<int> fullUnsortedVector, int& min, int& max){
    int length = fullUnsortedVector.size();
    
    if (length==1){
        fullUnsortedVector.push_back(fullUnsortedVector[0]);
        return fullUnsortedVector;
    }
    else if (length==2){
        if (fullUnsortedVector[0] < fullUnsortedVector[1]){
            return fullUnsortedVector;
        }
        else {
            int temp = fullUnsortedVector[0];
            fullUnsortedVector[0] = fullUnsortedVector[1];
            fullUnsortedVector[1] = temp;
            return fullUnsortedVector;
        }
    }
    else { 
        int mid = length/2;
        vector<int> firstHalf;
        vector<int> secondHalf;
        vector<int> firstHalfMinMax;
        vector<int> secondHalfMinMax;
        vector<int> finalMinMax;

        for (int i=0; i<mid; i++){
            firstHalf.push_back(fullUnsortedVector[i]);
        }
        divideAndConquer(firstHalf, min, max);
        int minFirstHalf = min;
        int maxFirstHalf = max;

        for (int i=mid; i<length; i++){
            secondHalf.push_back(fullUnsortedVector[i]);          
        }

        min = secondHalf[0];
        max = secondHalf[0];
        divideAndConquer(secondHalf, min, max); 
        int minSecondHalf = min;
        int maxSecondHalf = max;

        if (minFirstHalf < minSecondHalf){
            finalMinMax.push_back(minFirstHalf);
        }
        else {
            finalMinMax.push_back(minSecondHalf);
        }


        if (maxFirstHalf > maxSecondHalf){
            finalMinMax.push_back(maxFirstHalf);
        }
        else {
            finalMinMax.push_back(maxSecondHalf);
        }

        return finalMinMax; 
    }
}

void divideAndConquer(vector<int> halfUnsortedVector, int& min, int& max){
    if (halfUnsortedVector.size() < 1){ //base case
        return;
    }
    else {
        if (halfUnsortedVector[0] < min){
            min = halfUnsortedVector[0];
        }
        else if (halfUnsortedVector[0] > max){
            max = halfUnsortedVector[0];
        }
        else {
            min=min;
            max=max;
        }

        halfUnsortedVector.erase(halfUnsortedVector.begin());
        divideAndConquer(halfUnsortedVector, min, max); 
    }
}
