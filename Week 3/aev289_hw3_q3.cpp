#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a;
	int b;
	int c;
	
	cout << "Please enter a value for a: ";
	cin >> a;
	cout << "Please enter a value for b: ";
	cin >> b;
	cout << "Please enter a value for c: ";
	cin >> c;

	float x1= (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	float x2= (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

	if ((a == 0 && b== 0) && (c > 0))
	{
		cout << "There is no solution.";
	}
	else if (a == 0 && b == 0 && c == 0)
	{
		cout << "The equation has an inifinte number of solutions.";
	}
	else if ((pow(b, 2) - (4 * a * c)) > 0)
	{
		cout << "The equation has two real solutions: " << x1<< ", " << x2;
	}
	else if ((pow(b, 2) - (4 * a * c))==0)
	{
		cout << "The equation has a single real solution: " << x1;
	}
	else if ((pow(b, 2) - (4 * a * c)) < 0)
	{
		cout<< "There is no real solution.";
	}
	

	return 0;
}
