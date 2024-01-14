#include <iostream>
#include <string>

using namespace std;

bool areAnagrams(string str_1, string str_2);
void updateCount(int count_arr[], char ch);
const int ALPHABET=26;

int main()
{
    int letterCount;
    
    string string1, string2;
    cout<< "Input two lines of text and I will determine if they are an anagram."<< endl;
    cout<< "String 1: ";
    getline(cin, string1);
    cout<< endl;
    cout<<"String 2: ";
    getline(cin, string2);
    
    if(areAnagrams (string1, string2))
        cout<< "The 2 strings are anagrams."<< endl;
    else
        cout<< "The 2 strings are not anagrams."<< endl;;
    
    
    
    return 0;
}
bool areAnagrams(string str_1, string str_2)
{
    int count1_arr[ALPHABET]={};
    int count2_arr[ALPHABET]={};
    for(char ch: str_1)
    {
        updateCount(count1_arr, ch);
    }
    for (char ch: str_2)
    {
        updateCount(count2_arr, ch);
    }
    for(int i=0; i<ALPHABET; i++)
    {
        if(count1_arr[i] != count2_arr[i])
            return false;
    }
    return true;
}
void updateCount(int count_arr[], char ch)
{
    if (('a' <= ch) && (ch <= 'z'))
    {
        count_arr[ch - 'a']++;
    }
    else if (('A' <= ch) && (ch <= 'Z'))
    {
        count_arr[ch - 'A']++;
    }
}

