/*
Author: Amir Saad
This program converts values from binary to decimal and vice versa.
*/

#include "stdafx.h";
#include <iostream>;
#include <math.h>;
using namespace std;


int binToDec() 
{
	int binNum[8];
	int power = 7;
	int sum = 0;

	cout << "Enter an eight-bit binary number with a space between the bits: ";

	for (int i = 0; i < 8; i++) 
	{
		cin >> binNum[i];

		if (binNum[i] == 1)
		{
		binNum[i] = pow(2, power);
		}

		power--;

		sum = sum + binNum[i];
	}

	return sum;

}

void decToBin()
{
	int binNum[8];

	int num;

	cout << "Enter a decimal number: ";

	cin >> num;

	for (int i = 7; i >= 0; i--)
	{
		if(num % 2 == 1) 
			binNum[i] = 1;
		else 
			binNum[i] = 0;
	}

	cout << "The binary value of " << num << "(dec) is " << binNum[0] << binNum[1] << binNum[2] << binNum[3] << binNum[4] << binNum[5] << binNum[6] << binNum[7];

}

int toBinToDec()
{
	int binNum[8];
	int power = 7;
	int sum = 0;

	cout << "Enter an eight-bit two's complement binary number with a space between bits: ";

	for (int i = 0; i < 8; i++)
	{
		cin >> binNum[i];

		if(binNum[i] == 1)
		{
			binNum[i] = 0;
		}
		else
		{
			binNum[i] = 1;
		}

		binNum[i] = binNum[i] + 1;

		if (binNum[i] == 2)
			binNum[i] = 0;
	}

	for (int i = 0; i < 8; i++)
	{
		if (binNum[i] == 1)
		{
		binNum[i] = pow(2, power);
		}

		power--;

		sum = sum + binNum[i];
	}

	return sum * -1;
	
}

void decToToBin()
{
	int binNum[8];
	int num;

	cout << "Enter a decimal number: ";

	cin >> num;

	for (int i = 7; i >= 0; i--)
	{
		if(num % 2 == 1) 
		{
			binNum[i] = 1;
		}
		else 
		{
			binNum[i] = 0;
		}
	}

	for (int i = 0; i < 8; i++) 
	{
		if(binNum[i] == 1)
		{
			binNum[i] = 0;
		}
		else
		{
			binNum[i] = 1;
		}

		binNum[i] = binNum[i] + 1;

		if (binNum[i] == 2)
			binNum[i] = 0;
	}

	cout << "The binary value of " << num << "(dec) is " << binNum[0] << binNum[1] << binNum[2] << binNum[3] << binNum[4] << binNum[5] << binNum[6] << binNum[7] << " (bin).";
}

int main()
{
	int input;

	do {
		cout << "Welcome to the Number Conversion Program!" << endl;
		cout << "-----------------------------------------" << endl;
		cout << "(1) Convert unsigned binary to unsigned decimal" << endl << "(2) Convert unsigned decimal to unsigned binary" << endl << "(3) Convert two's complement binary to decimal" << endl << "(4) Convert decimal to two's complement binary" << endl << "(5) Exit the program" << endl;
		cout << "Your choice?: ";

		cin >> input;

		switch (input) 
		{
			case 1: int result = binToDec();
					cout << "The decimal value of your entered binary number is " << result;
					break;

			case 2: decToBin();
					break;

			case 3: int result = toBinToDec();
					cout << "The decimal value of your entered binary number is " << result;
					break;

			case 4: decToToBin();
					break;

			default: break;
		}

		

	} while (true);

	cin.ignore();
	return 0;
	
}


