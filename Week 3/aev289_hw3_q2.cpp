#include <iostream>
#include <string>

using namespace std;

int main()
{
	string name;
	string status;
	int gradyear;
	int curryear;

	cout << "Please enter your name: ";
	cin >> name;
	cout << "\n";
	cout << "Please enter your graduation year: ";
	cin >> gradyear;
	cout << "\n";
	cout << "Please enter current year: ";
	cin >> curryear;
	cout << "\n";

	if (curryear >= gradyear)
	{
		status = "Graduated";
	}
	else if (gradyear == (curryear + 3))
	{
		status = "a Sophomore";
	}
	else if (gradyear == (curryear + 4))
	{
		status = "a Freshman";
	}
	else if (gradyear == (curryear + 2))
	{
		status = "a Junior";
	}
	else if (gradyear == (curryear + 1))
	{
		status = "a Senior";
	}
	else if (gradyear > (curryear + 4))
	{
		status = "not in college yet";
	}

	cout << name << ", you are " << status;
	return 0;
}