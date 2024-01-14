#include <iostream>
using namespace std;

int main()
{
    int dec, binary=0, product=1, remainder;
    
    cout<<"Enter a decimal number: ";
    cin >> dec;
    
    while(dec !=0)
    {
        remainder = dec % 2;
        binary = binary + (remainder * product);
        dec = dec / 2;
        product *= 10;
        
    }
    cout << "\n The number in binary form is: "<< binary;
    
    
    return 0;
}
