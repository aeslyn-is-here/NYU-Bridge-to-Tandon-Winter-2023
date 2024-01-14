#include <iostream>
using namespace std;

int main()
{
	int john_days, john_hours, john_minutes, bill_days, bill_hours, bill_minutes;
	int total_days;
	int total_hours;
	int total_min;

	cout << "Please enter the number of days John has worked: ";
	cin >> john_days;
	cout << "\n";
	cout << "Please enter the number of hours John has worked: ";
	cin >> john_hours;
	cout << "\n";
	cout << "Please enter the number of minutes John has worked: ";
	cin >> john_minutes;
	cout << "\n \n";
	cout << "Please enter the number of days Bill has worked: ";
	cin >> bill_days;
	cout << "\n";
	cout << "Please enter the number of hours Bill has worked: ";
	cin >> bill_hours;
	cout << "\n";
	cout << "Please enter the number of minutes Bill has worked: ";
	cin >> bill_minutes;
	cout << "\n";

	int total = (john_days * 1440) + (bill_days * 1440) + (john_hours * 60) + (bill_hours * 60) + john_minutes + bill_minutes;
	total_days = total /1440;
	total = total % 1440;
	total_hours = total / 60;
	total = total % 60;
	total_min = total / 1;

	cout << "The total time both of them worked together is " << total_days << " days, " << total_hours << " hours, and " << total_min << " minutes." << endl;

	return 0;
}
