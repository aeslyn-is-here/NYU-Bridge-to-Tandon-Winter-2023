#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <list>
#include <string>
using namespace std;

void openfile(ifstream &fileObj)
{
   string pathName;
   cout << "Enter the name of the file:" << endl;
   cin >> pathName;
   fileObj.open(pathName);
   while (!fileObj) {
       cout << "Error, double check pathname and reenter" << endl;
       cin >> pathName;
       fileObj.clear();
       fileObj.open(pathName);
   }
};

void readingFile(ifstream& file, list<string>& tags){
    string symbols;
    char temp;
    file>>symbols;
    file>>symbols;
    for(int i=0; i< symbols.size(); i++)
    {
        temp=symbols[i];
        if (temp=='{'||temp=='['|| temp=='('||temp=='}'||temp==']'|| temp==')')
            tags.push_back(symbols);
        
    }
};

bool validMarkUp(list<string>& tags){
    stack<string> open;
    while (!tags.empty()){
        string temp = tags.front();
        if(temp[0]=='('||temp[0]=='['||temp[0]=='{')
        {
            open.push(temp);
        }
        else if(temp[0]==')')
        {
            if(open.empty() || open.top()[0]!='(')
            {
                return false;
            }
            open.pop();
        }
        else if(temp[0]==']')
        {
            if(open.empty() || open.top()[0]!='[')
            {
                return false;
            }
            open.pop();
        }
        else if(temp[0]=='}')
        {
            if(open.empty() || open.top()[0]!='{')
            {
                return false;
            }
            open.pop();
        }
        tags.pop_front();
   }
   return open.empty();
};

int main()
{
    ifstream file;
    openfile(file);
    list<string> tags;
    readingFile(file, tags);
    cout<<boolalpha<< validMarkUp(tags);
    return 0;
}
