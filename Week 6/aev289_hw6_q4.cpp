#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num);

int main()
{
    int n;

    cout << "Please enter a positive integer >= 2: ";
    cin >> n;
    printDivisors(n);

    
    return 0;
}
void printDivisors(int num)
{
    double sqrt= pow(num, 0.5);
    
    for(int i=1; i<=sqrt; i++)
    {
        if (num % i == 0)
        {
            cout << i << " ";
        }
    }
    for (int i = sqrt; i > 1; i--) {
        if (num % i == 0)
        {
            cout << num / i <<" ";
        }
    }
    cout<< num;
}
