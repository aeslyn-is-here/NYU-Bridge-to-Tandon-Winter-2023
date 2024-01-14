#include <iostream>
using namespace std;

int main()
{
	//Part A

	int num;

	cout << "Please enter a postive intiger: " << endl;
	cin >> num;
	int i = 1;
	int output = 2;
	while (i <= num)
	{
		if (output % 2 == 0)
		{
			cout << output << endl;
			i++;
		}
		output++;
	}

	//Part B

	int num2;
	cout << "Please enter a postive integer: " << endl;
	cin >> num2;
	int output2 = 2;
	for (int i2 = 0; i2 < num2; output2++)
	{
		if (output2 % 2 == 0)
		{
			cout << output2 << endl;
			i2++;
		}
	}
	return 0;
}