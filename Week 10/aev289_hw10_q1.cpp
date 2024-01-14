#include <iostream>
#include <string>

using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);

int main()
{
    string sentence;
    
    cout<< "Please input a sentance: "<<endl;
    getline(cin, sentence);
    
    int wordsize;
    
   string* words_arr= createWordsArray(sentence, wordsize);
    
    cout<< "Words array: [";
    for(int i=0; i< wordsize; i++)
    {
        cout<< "\""<< words_arr[i] << "\"";
        if (i != wordsize - 1)
        {
            cout << ", ";
        }
    }
    cout<< "]"<< endl;
    
    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize)
{
    int start=0;
    int word_count=0;
    string*words_arr= new string[sentence.length()];
    for (int end = 0; end < sentence.length(); end++)
    {
        if (sentence[end] == ' ')
        {
            words_arr[word_count++] = sentence.substr(start, end - start);
            start = end + 1;
        }
    }
    
    words_arr[word_count++] = sentence.substr(start);
    outWordsArrSize= word_count;
    
    return words_arr;
    
}
