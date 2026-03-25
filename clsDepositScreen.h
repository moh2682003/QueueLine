#pragma once 
#include "clsScreen.h"

class clsDepositScreen : clsScreen
{
	static double _ReadAmount()
	{
		double Amount;
		cout << "Enter Amount: ";
		Amount = clsInputValidate::ReadDblNumber();
		return Amount;
	}

public:

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("Deposit Screen");

		double Amount = _ReadAmount();

		char Answer;

		cout << "Are You sure to Deposit " << Amount << "? [y/n]: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			CurrentClient.Deposit(Amount);
			cout << "\n\nSuccessful Transaction :)\n";
			cout << "New Balance In Account: " << CurrentClient.AccountBalance;
		}
		else
		{
			cout << "Cancelled Transaction :)";
		}
	}
};

