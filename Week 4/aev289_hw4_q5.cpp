#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<< "Please input a positive integer: ";
    cin >> n;
    cout<< endl;
    
    for (int i=n; i>0; i--)
    {
        for(int j=n; i<j; j--)
        {
            cout << " ";
        }
        for (int b= 0; b<((2*i)-1); b++)
        {
            cout<<"*";
        }
        cout<< endl;
    }
    for (int i=0; i<n; i++)
    {
        for(int j=i; j<(n-1); j++)
        {
            cout<< " ";
        }
        for(int b=0;b<((2*i)+1);b++)
        {
            cout<< "*";
        }
        cout<< endl;
    }
    return 0;
}
