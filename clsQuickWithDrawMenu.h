#pragma once 
#include "clsScreen.h"
class clsQuickWithDrawMenu : clsScreen
{
	static short ReadQuickWithDrawChose()
	{
		short Choese;
		cout << "\t\t\t\t\tSelect Number[1:6]: ";
		Choese = clsInputValidate::ReadNumberBetween(1, 7, "Out Valid Select Again: ");
		return Choese;
	}

	static void _PerFromQuickWithDrawMenu(int Number)
	{
		switch (Number)
		{
			case 1 :
				CurrentClient.WithDraw(50);
				break;
			case 2:							 
				CurrentClient.WithDraw(100);
				break;
			case 3:							 
				CurrentClient.WithDraw(200);
				break;
			case 4:							 
				CurrentClient.WithDraw(500);
				break;
			case 5 :						 
				CurrentClient.WithDraw(1000);
				break;
			case 6:							 
				CurrentClient.WithDraw(2000);
				break;
			case 7 :						 
				CurrentClient.WithDraw(5000);
				break;
			default :
				CurrentClient.WithDraw(0);

		}
	}
	
public:

	static void ShowQuickWithDrawMenu()
	{
		_DrawScreenHeader("Quick WithDraw Menu");
		cout << "\t\t\t\t\t===========================================\n";
		cout << "\t\t\t\t\t[1]50 \t [2]100\n\n";
		cout << "\t\t\t\t\t[3]200 \t [4]500\n\n";
		cout << "\t\t\t\t\t[5]1000  [6]2000\n\n";
		cout << "\t\t\t\t\t\t[7]5000\n";
		cout << "\t\t\t\t\t====================================================\n";
		_PerFromQuickWithDrawMenu(ReadQuickWithDrawChose());


		cout << "Successful Transaction\n\n";
		cout << "New Balance: " << CurrentClient.AccountBalance;
	}

};

