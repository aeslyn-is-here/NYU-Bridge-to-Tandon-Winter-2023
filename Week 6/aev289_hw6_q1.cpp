#include <iostream>
using namespace std;

int fibseq(int num);

int main()
{
    int num;
    int result;
    
    cout<< "Please enter a positive integer: "<< endl;
    cin>> num;
    cout<< endl;
    result= fibseq(num);
    
    cout<< result;
    
    return 0;
}

int fibseq(int num)
{
    int n1=0, n2=1,result=0;
    
    for(int i=1; i<=num; i++)
    {
        n1=n2;
        n2=result;
        result=n1+n2;
    }
    return result;
    
}
