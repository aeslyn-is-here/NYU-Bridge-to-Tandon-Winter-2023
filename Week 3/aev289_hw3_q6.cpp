#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    string day;
    int minutes;
    char temp;
    int hours;
    double minutes_spent;
    double cost;
    
    cout<< "What day did this call occur on?(Enter as Mo, Tu, We, Th, Fr, Sa, Su)";
    cin >> day;
    cout << "\n";
    cout<< "What time did this call occur?(in 24 hour notation)"<< endl;
    cin >> hours >> temp >> minutes;
    cout << " \n";
    cout << "What was the length of the call in mimutes?";
    cin >> minutes_spent;
    cout << "\n";
    
    if (( day == "Mo" || day== "Tu" || day== "We" || day== "Th" || day=="Fr") && (hours >= 8 || hours <=18))
    {
        cost= minutes_spent* .40;
    }
    else if (( day == "Mo" || day== "Tu" || day== "We" || day== "Th" || day=="Fr") && (hours <= 8 || hours >=18))
    {
        cost= minutes_spent* .25;
    }
    else if (day== "Sa" || day== "Su")
    {
        cost= minutes_spent* .15;
    }
    
    cout<< fixed << showpoint << setprecision(2);
    
    cout << "The cost of the call is $" << cost<< endl;
    
    
    return 0;
    
}
