#include <iostream>
#include  <cstdlib> 
using namespace std;

int main()
{
	int one;
	int two;

	cout << "Please enter two positive integers, seperated by a space: ";
	cin >> one >> two;

	cout << one << "+" << two << "=" << one + two << endl;
	cout << one << "-" << two << "=" << one - two << endl;
	cout << one << "*" << two << "=" << one * 2 << endl;
	cout << one << "/" << two << "=" << (float)one / two << endl;
	div_t result1= div(one, two);
	cout << one << " div " << two << "=" << result1.quot << endl;
	cout << one << " mod " << two << "=" << one % 2 << endl;

	return 0;
}