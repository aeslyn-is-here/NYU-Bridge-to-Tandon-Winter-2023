#include <iostream>
#include <cmath>

using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);
int main()
{
    int n, countDiv, sumDiv;
    
    cout<< "Please input a positive integer greater than or equal to 2: "<< endl;
    cin>> n;
    
    analyzeDividors(n, countDiv,sumDiv);
    cout<<"Perfect numbers between 2 and "<< n << " are:"<< endl;
    for(int i = 2; i <= n; i++)
    {
        if(isPerfect(i))
        {
            cout << i << " ";;
        }
    }
    cout << endl;
    cout<< "Amicable pairs between 2 and "<< n<< " are: "<< endl;
     for(int i = 2; i <= n; i++)
     {
         int amPair;
         analyzeDividors(i, countDiv, amPair);
         analyzeDividors(amPair, countDiv, sumDiv);
         if(i == sumDiv && i > amPair)
         {
             cout << "(" << amPair << ", " << i << ")";
         }
     }
     cout << endl;
    
    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs)
{
    int sum = 1;
    int count = 1;
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        {
            count += 2;
            sum += i + num / i;
        }
    }
    outCountDivs = count;
    outSumDivs = sum;
      
}
bool isPerfect(int num)
{
    int sum;
    int count;
    analyzeDividors(num, count, sum);
    return num == sum;
}
