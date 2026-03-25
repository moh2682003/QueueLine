#pragma once
#include "clsScreen.h"

class clsShowBalanceScreen : protected clsScreen 
{
	
public :

	static void ShowTotalBalance()
	{
		_DrawScreenHeader("Total Balance");
		cout << "Total Balance: " << CurrentClient.AccountBalance;
	}
};

