#include <iostream>
#include <string>

using namespace std;

bool isNum(string word);
string oneWord(string word);

int main()
{
    string input;
    cout<<"Please enter a line of text: "<< endl;
    getline(cin,input);
    
    for(int start=0, end=0; end<=input.length(); end++)
    {
        if(end==input.length()|| input[end]==' ')
        {
            string word = input.substr(start, end - start);
            cout << oneWord(word) << ' ';
            start = end + 1;
        }
    }
    
    
    return 0;
}

bool isNum(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i]>'9')
        {
            return false;
        }
    }

       return true;
}

string oneWord(string word)
{
    if( isNum(word))
    {
        string oneWord;
        
        for (int i = 0; i < word.length(); i++)
        {
                 oneWord+= 'x';
        }
        return oneWord;
    }
    else
    {
        return word;
    }
}
