#include <iostream>
#include <cmath>

using namespace std;

int main()
{

	double height_in;
	double weight_lb;
	double weight_kg;
	double height_met;
	double bmi;

	cout << "Please enter your weight(in pounds): ";
	cin >> weight_lb;
	cout << "\n";
	cout << "Please enter your height(in inches): ";
	cin >> height_in; 
	cout << " \n";

	weight_kg = weight_lb * 0.453592;
	height_met = height_in * 0.0254;
	 

	bmi = weight_kg/ (pow(height_met, 2.0));


	if (bmi <= 18.5)
	{
		cout << "The weight status is: Underweight";
	}
	else if (bmi <= 25)
	{
		cout << "The weight status is: Normal";
	}
	else if (bmi <= 30)
	{
		cout << "The weight status is: Overweight";
	}
	else if (bmi > 30)
	{
		cout << "The weight status is: Obese";
	}

	return 0;
}