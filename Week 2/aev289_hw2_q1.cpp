#include <iostream>
using namespace std;

int main()
{
	float quarter_amt, dime_amt, nickel_amt, penny_amt;
	const double QUARTER = .25;
	const double DIME = .10;
	const double NICKEL = .05;
	const double PENNY = .01;
	int total_dollars;
	float total_cents;


	cout << "Please enter number of coins: " << endl;
	cout << "# of quarters: ";
	cin >> quarter_amt; 
	cout << "\n";
	cout << "# of dimes: ";
	cin >> dime_amt; 
	cout << "\n";
	cout << "# of nickels: ";
	cin >> nickel_amt;
	cout << "\n";
	cout << "# of pennies: ";
	cin >> penny_amt;

	total_dollars = (quarter_amt * QUARTER) + (dime_amt * DIME) + (nickel_amt * NICKEL) + (penny_amt * PENNY);
	total_cents = ((quarter_amt * QUARTER) + (dime_amt * DIME) + (nickel_amt * NICKEL) + (penny_amt * PENNY) - total_dollars) * 100;
	cout << "The total is " << total_dollars << " dollars and " << total_cents << " cents";

	return 0;

}
