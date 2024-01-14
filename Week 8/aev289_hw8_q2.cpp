#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str);

int main()
{
    string word;
    
    cout<< "Please enter a word: ";
    cin>> word;
    if(isPalindrome(word))
    {
        cout<< word << " is a palindrome.";
    }
    else
    {
        cout<< word << " is not a palindrome.";
    }
    
    
    return 0;
}
bool isPalindrome(string str)
{
    int length= str.length();
    int backVal=length-1;
    int frontVal=0;
    int test=0;
    
    while(str[frontVal]==str[backVal] && frontVal< backVal)
    {
        test++;
        backVal--;
        frontVal++;
    }
    if(test==length/2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
