#include <iostream>
using namespace std;

int main()
{
	float quarter_amt, dime_amt, nickel_amt, penny_amt;
	float dollars;
	float cents;
	int total;

	cout << "Please enter your amount in the ofrmat of dollars and cents seperated by a space: ";
	cin >> dollars;
	cin >> cents;

	total = (dollars + (cents / 100)) * 100;
	quarter_amt = total / 25;
	total = total % 25;
	dime_amt = total / 10;
	total = total % 10;
	nickel_amt = total / 5;
	total = total % 5;
	penny_amt = total / 1;

	cout << dollars << " dollars and " << cents << " cents are: " << endl;
	cout << quarter_amt << " quarters, " << dime_amt << " dimes, " << nickel_amt << " nickels, and " << penny_amt << " pennies.";


	return 0;


}