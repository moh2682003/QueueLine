#pragma once 
#include "clsScreen.h"

class clsWithDrawScreen : clsScreen
{
	static double _ReadAmount()
	{
		double Amount;
		cout << "Enter Amount: ";
		Amount = clsInputValidate::ReadDblNumber();
		while (Amount > CurrentClient.AccountBalance)
		{
			cout << "Cannot Perform This Transaction :-(\n\n";
			cout << "Maximum Amount is [" << CurrentClient.AccountBalance << "]";
			cout << "\nEnter Amount: ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}

public:

	static void ShowWithDrawScreen()
	{
		_DrawScreenHeader("With Draw Screen");

		double Amount = _ReadAmount();

		char Answer;

		cout << "Are You sure to With Draw " << Amount << "? [y/n]: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			CurrentClient.WithDraw(Amount);
			cout << "\n\nSuccessful Transaction :)\n";
			cout << "New Balance In Account: " << CurrentClient.AccountBalance;
		}
		else
		{
			cout << "Cancelled Transaction :)";
		}
	}
};

