#include <iostream>
#include <string>
using namespace std;

int main()
{
    string firstName, lastName, middleName;
    
    cout<< "Pleas input your first, middle, and last name: " << endl;
    
    cin>> firstName>> middleName >> lastName;
    cout<< endl;
    
    cout<< lastName <<", "<< firstName<<" " <<middleName[0];
    
    
    return 0;
}
