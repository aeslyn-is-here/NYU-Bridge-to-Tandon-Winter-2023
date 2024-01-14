#include <iostream>
#include <string>
using namespace std;

int main()
{

int input, num;
string romanNum= " ";

cout << "Enter a decimal number: ";
cin>> input;

num=input;

if(input>=1000)
{
    for (input; input>=1000; input-=1000)
    {
        romanNum= romanNum+ "M";
    }
}
if (input >=500)
{
    for(input; input >=500; input-=1000)
    {
        romanNum= romanNum+ "D";
    }
}
if (input >=100)
{
    for(input; input >=100; input-=100)
    {
        romanNum= romanNum+ "C";
    }
}
if (input >=50)
{
    for(input; input >=50; input-=50)
    {
        romanNum= romanNum+ "L";
    }
}
if (input >=10)
{
    for(input; input >=10; input-=10)
    {
        romanNum= romanNum+ "X";
    }
}
if (input >=5)
{
    for(input; input >=5; input-=5)
    {
        romanNum= romanNum+ "V";
    }
}
if (input >=1)
{
    for(input; input >=1; input-=1)
    {
        romanNum= romanNum+ "I";
    }
}
cout<< num << " is " << romanNum;
return 0;
}
