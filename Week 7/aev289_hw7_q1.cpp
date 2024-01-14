#include <iostream>
using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
void printYearCalender(int year, int startingDay);
bool determineLeapYr(int year);

const int WEEK_DAYS = 7;
const int YEAR_MONTHS = 12;

int main()
{
    int year;
    int start_day;
    cout<< "Please enter a year and a number 1-7 representing the day of the week the year began(1=Monday, 2=Tuesday, 3=Wednesday...7=Sunday), seperated by a space. " <<endl;
    cin>> year >> start_day;
    printYearCalender(year, start_day);
    
    
    return 0;
}

int printMonthCalender(int numOfDays, int startingDay)
{
    int dayCount = numOfDays;
    int dayStart = startingDay;
    cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun" << endl;

    for (int i=1; i <= dayStart - 1; i++)
    {
        cout << "\t";
    }

    for (int k=1; k <= dayCount; k++)
    {

       cout << k << "\t";
        dayStart++;

        if (dayStart > WEEK_DAYS)
        {
            cout<< endl;
            dayStart = 1;
        }
    }
    cout << endl;

    return dayStart;
}
bool determineLeapYr(int year)
{
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}
void printYearCalender(int year, int startingDay)
{
    int newStartDay, numDays, month;
    for (month=1; month <= YEAR_MONTHS; month++)
    {
        cout << endl;
        switch (month)
        {
            case 1:
                cout << "January " << year << endl;
                numDays = 31;
                newStartDay = printMonthCalender(numDays, startingDay);
                break;
            case 2:
                cout << "February " << year << endl;
                if (determineLeapYr(year))
                {
                    numDays = 29;
                }
                else
                {
                    numDays = 28;
                }
                newStartDay = printMonthCalender(numDays, newStartDay);
                break;
            case 3:
                cout << "March " << year << endl;
                numDays = 31;
                newStartDay = printMonthCalender(numDays, newStartDay);
                break;
            case 4:
                cout << "April " << year << endl;
                numDays = 30;
                newStartDay = printMonthCalender(numDays, newStartDay);
                break;
            case 5:
                cout << "May " << year << endl;
                numDays = 31;
                newStartDay = printMonthCalender(numDays, newStartDay);
                break;
            case 6:
                cout << "June " << year << endl;
                numDays = 30;
                newStartDay = printMonthCalender(numDays, newStartDay);
                break;
            case 7:
                cout << "July " << year << endl;
                numDays = 31;
                newStartDay = printMonthCalender(numDays, newStartDay);
                break;
            case 8:
                cout << "August " << year <<endl;
                numDays = 31;
                newStartDay = printMonthCalender(numDays, newStartDay);
                break;
            case 9:
                cout << "September " << year << endl;
                numDays = 30;
                newStartDay = printMonthCalender(numDays, newStartDay);
                break;
            case 10:
                cout << "October " << year << endl;
                numDays = 31;
                newStartDay = printMonthCalender(numDays, newStartDay);
                break;
            case 11:
                cout << "November " << year << endl;
                numDays = 30;
                newStartDay = printMonthCalender(numDays, newStartDay);
                break;
            case 12:
                cout << "December " << year << endl;
                numDays = 31;
                newStartDay = printMonthCalender(numDays, newStartDay);
                break;
        }
    }
}
