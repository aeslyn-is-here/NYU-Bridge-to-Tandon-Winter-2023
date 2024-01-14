#include <iostream>
using namespace std;

int main()
{
	const int FLOOR_ROUND = 1;
	const int CEILING_ROUND = 2;
	const int ROUND = 3;

	double num;
	int selection;

	cout << "Please enter a real number: " << endl;
	cin >> num;
	cout << "Choose your rounding method:" << endl;
	cout << "1. Floor round" << endl;
	cout << "2. Ceiling round" << endl;
	cout << "3. Round to the nearest whole number" << endl;
	cin >> selection;

	switch (selection) {
		case FLOOR_ROUND:
		{
			int newnum = (int)(num - 0.5);
			cout << newnum;
		}
		break;
		case CEILING_ROUND:
		{
			int floornum = (int)(num + 0.5);
			cout << floornum;
		}
		break;
		case ROUND:
		{
			int rounded = (int)(num + 0.5);
			cout << rounded;
		}
		break;
	}



	return 0;
}