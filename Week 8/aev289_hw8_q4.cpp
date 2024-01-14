#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;


void printFormattedPin(const string str);
string createRandomPin(string str);
string inputPin();
bool comparePins(string pinPad, string randomPin, string inputPin, string pin);

const string PIN= "12345";
const string PIN_PAD= "0123456789";


int main()
{
    cout<< "Please input a pin according to the following mapping:"<< endl;
    cout<< "PIN: ";
    printFormattedPin(PIN_PAD);
    cout<< endl;
    cout<< "NUM: ";
    string randomPin=createRandomPin(PIN_PAD);
    printFormattedPin(randomPin);
    cout<< endl;
    string pinInput= inputPin();
    if(comparePins(PIN_PAD, randomPin, pinInput, PIN))
    {
        cout<< "Your pin is correct.";
    }
    else
    {
        cout<< "Your pin is wrong." ;
    }
        
    return 0;
}

void printFormattedPin(const string str)
{
    int length= str.length();
    for(int i=0; i<length; i++)
    {
        cout<< str[i]<< "  ";
    }
    
}
string createRandomPin(string str)
{
        string nums=PIN_PAD;
        int length= nums.length();
        char dig[3]={'1', '2','3'};
        srand(time(0));
        for(int i=0;i<length; i++)
        {
            nums[i]=dig[(rand() % 3)];
        }
        
    return nums;
}
string inputPin()
{
    string pin;
    cout<< "Please enter a " << PIN.length()<< " digit length pin: "<< endl;
    cin>> pin;
    return pin;
}
bool comparePins(string pinPad, string randomPin, string inputPin, string pin)
{
    char temp;
    for(int i=0; i<pin.length(); i++)
    {
        temp= pin[i];
        for(int j=0; j<pinPad.length(); j++)
        {
            if(pinPad[j]==temp)
            {
                if(randomPin[j]!=inputPin[i])
                {
                    return false;
                }
            }
        }
        
    }
    return true;
}

