#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Please input a postivie integer: ";
    cin>> n;
    cout<< endl;
    
    for(int i=1, b=0; (i-1)<n;i++, b++)
    {
        for(int j=1; (j-1)<n; j++)
        {
            cout << j*i << "\t";
        }
        cout<< endl;
    }
    
    return 0;
}
