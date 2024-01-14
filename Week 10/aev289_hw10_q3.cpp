#include <iostream>
#include <vector>

using namespace std;

void resize_array(int*& arr, int& size, int newSize);
int* searchResults(int num, const int lines[], int lineSize, int& occurenceCount);
vector<int> searchVecResults(int num, const vector<int>& lines);
int main()
{
    //Version 1
    const int START_SIZE = 5;
    int size = START_SIZE;
    int* lines = new int[size];
    int lineSize = 0;

    cout << "Please enter a sequence of positive integers, each in a separate line."<<endl;
    cout << "End by typing -1."<<endl;

    while (true)
    {
        int input;
        cin >> input;
        if (input == -1)
        {
            break;
        }
        else
        {
            lines[lineSize++] = input;
            
            if (lineSize == size)
            {
                resize_array(lines, size, size * 2);
            }
        }
    }
    
    int num;
    cout<< "Enter the number you want to search for: "<<endl;
    cin>> num;
    
    int occurenceCount;
    int* result= searchResults(num, lines, lineSize, occurenceCount);
    
    if(occurenceCount==0)
    {
        cout<< num << " does not appear in the sequence you entered. "<<endl;
    }
    else
    {
        cout<< num<< " appears in lines ";
        for (int i = 0; i < occurenceCount; i++)
        {
            if (i == occurenceCount - 1)
            {
                cout << result[i] << "."<<endl;
            }
            else
            {
                cout << result[i] << ", ";
            }
        }
    }
    
   
    ////Version 2
    vector <int> lines_vec;
    cout << "Please enter a sequence of positive integers, each in a separate line."<<endl;
    cout << "End by typing -1."<<endl;
    while (true)
    {
        int input_vec;
        cin >> input_vec;

        if (input_vec == -1) {
            break;
        } else
        {
            lines_vec.push_back(input_vec);
        }
    }
    int num2;
    cout<< "Enter the number you want to search for: "<<endl;
    cin>> num2;
    vector<int> results = searchVecResults(num2, lines_vec);
    if(results.empty())
    {
        cout<< num2 << " does not appear in the sequence you entered. "<<endl;
    }
    else
    {
        cout<< num2 << " appears in lines ";
        for (int i = 0; i < results.size(); i++)
        {
            if (i == results.size()- 1)
            {
                cout << results[i] << "."<<endl;
            }
            else
            {
                cout << results[i] << ", ";
            }
        }
    }
    return 0;
}

void resize_array(int*& arr, int& size, int newSize)
{
    int* temp = new int[newSize];
    
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }
    
  
    arr = temp;
    delete [] arr;
    size = newSize;
}

int* searchResults(int num, const int lines[], int lineSize, int& occurenceCount)
{
    int* searchResults = new int[lineSize];
    int count = 0;

        for (int i = 0; i < lineSize; i++)
        {
            if (lines[i] == num)
            {
                searchResults[count++] = i + 1;
            }
        }

    occurenceCount = count;

    return searchResults;
}

vector<int> searchVecResults(int num, const vector<int>& lines)
{
    vector<int> results;
    for(int i=0; i<lines.size(); i++)
    {
        if(lines[i]==num)
        {
            results.push_back(i+1);
        }
    }
    return results;
}
