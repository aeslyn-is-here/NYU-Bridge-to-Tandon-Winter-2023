#include <iostream>
#include <string>
using namespace std;

bool isNotText(char ch);
void occurenceUpdate(int count_arr[], char c);

int main()
{
    const int ALPHABET=26;
    int wordCount=0;
    int letterCount=0;
    int count_arr[ALPHABET]={};
    
    string input;
    cout<<"Please input a line of text: "<< endl;
    getline(cin, input);
    for (char ch: input)
    {
        if (isNotText(ch))
        {
            if (letterCount > 0)
            {
                wordCount++;
            }
            
            letterCount = 0;
        }
        else
        {
            occurenceUpdate(count_arr, ch);
            letterCount++;
        }
    }
    cout<< wordCount<< "\twords" << endl;
    for (int i = 0; i < ALPHABET; i++)
    {
        if (count_arr[i] > 0)
        {
            cout << count_arr[i] << "\t" << static_cast<char>('a' + i) << endl;
        }
    }
            
            
    return 0;
}
        
bool isNotText(char ch)
{
    if ((ch == ' ') || (ch == ',') || (ch == '.'))
        return true;
    else
        return false;
}
void occurenceUpdate(int count_arr[], char ch)
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
