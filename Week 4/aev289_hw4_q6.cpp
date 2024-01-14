#include<iostream>

using namespace std;

int main()
{
   int n, oddC, evenC, num, rem;
   cout<<"Enter a positive number: ";
   cin>>n;
   
   
   for(int i = 1;i<=n;i++)
   {
      num = i;
      oddC = 0;
      evenC = 0;
      while(i != 0)
      {
         rem = i % 10;
         if(rem % 2 == 1)
         {
            oddC++;
         }
         else
         {
            evenC++;
         }
         i = i / 10;
      }
      i = num;
      if(evenC > oddC)
      {
          cout<<num<< endl;
      }
   }
   return 0;
}
