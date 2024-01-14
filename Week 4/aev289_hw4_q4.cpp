#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double sequenceL;
    
    cout << "a. Please enter the length of the sequence: ";
    cin>> sequenceL;
    
 
    cout << "\n Please enter your sequence: ";
    double product=1;
    double value;
    
    for(int count=1; count<=sequenceL; count++)
    {
        cin >> value;
        product= product*value;
    }
  
    double geoMean= pow(product,(1/sequenceL));
    cout<< fixed<< showpoint << setprecision(5);
    
    cout<< "\n The Geometric Mean is: " << geoMean;
    
    
    cout<< "b. Please enter a non-empty sequence of positive integers, each one in a seperate line. End \n";
    cout<< " your sequence by typing -1:";
    
    double sL2;
    int value2;
    double product2=1;
    cin >> value2;
    
    while(value2>-1)
    {
        sl2++;
        product2=value2*products;
        cin >> value2;
    }
    double geoMean2= pow(product2/ (1/sL2));
    
    cout << "The geometric mean is " << geoMean2;
    
    return 0;
}

