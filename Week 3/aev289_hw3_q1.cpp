#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double item1;
	double item2;
	char clubc;
	double taxrate;
	double baseprice;
	double discountprice;
	double totalprice;

	cout << "Enter price of first item: ";
	cin >> item1;
	cout << "\n";
	cout << "Enter price of second item: ";
	cin >> item2;
	cout << "\n";
	cout << "Does the customer have a club card?(Y/N): ";
	cin >> clubc;
	cout << "\n";
	cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
	cin >> taxrate;
	cout << "\n";

	baseprice = item1 + item2;

	if (item1 > item2)
	{
		if (clubc == 'y' || clubc == 'Y')
		{
			double newprice = (item1 + (item2 / 2));
			discountprice = newprice - (newprice * .10);
		}
		else if (clubc == 'n' || clubc == 'N')
		{
			discountprice = item1 + (item2 / 2);
		}
	}
	else if (item2 > item1)
	{
		if (clubc == 'y' || clubc == 'Y')
		{
			double newprice = (item2 + (item1 / 2));
			discountprice = newprice - (newprice * .10);
		}
		else if (clubc == 'n' || clubc == 'N')
		{
			discountprice = item2 + (item1 / 2);
		}
	}

	totalprice = discountprice + (discountprice * (taxrate / 100));

	cout << "Base price: " << baseprice << endl;
	cout << "Price afrer discount: " << discountprice << endl;
	cout << "Total price: " << totalprice << endl;

	return 0;
}