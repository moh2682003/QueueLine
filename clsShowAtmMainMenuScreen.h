#pragma once 
#include "clsScreen.h"
#include "clsShowBalanceScreen.h"
#include "clsQuickWithDrawMenu.h"
#include "clsWithDrawScreen.h"
#include "clsDepositScreen.h"
#include "clsChangePinCodeScreen.h"

class clsShowAtmMainMenuScreen : clsScreen
{
	enum enAtmMainMenuOpetion {aShowBalance = 1 , aQuickWithDraw = 2 , aWithDraw = 3 , 
		aDeposit = 4 , aChangePinCode = 5 , aLogOut = 6};


	static void _ShowBalanceScreen()
	{
		system("cls");
		clsShowBalanceScreen::ShowTotalBalance();
	}

	static void _ShowQuickWithDrawScreen()
	{
		system("cls");
		clsQuickWithDrawMenu::ShowQuickWithDrawMenu();
	}

	static void _ShowWithDrawScreen()
	{
		system("cls");
		clsWithDrawScreen::ShowWithDrawScreen();
	}

	static void _ShowDepositScreen()
	{
		system("cls");
		clsDepositScreen::ShowDepositScreen();
		
	}

	static void _ShowChangePinCode()
	{
		system("cls");
		clsChangePinCodeScreen::ShowChangePinScreen();
	}

	static void _ShowLogOutScreen()
	{
		system("cls");
		cout << "\n\n\nThank you for using our ATM.Have a nice day! :-)\n\n";
		system("pause>0");
	}

	static void _GoBackToMainMenu()
	{
		cout << "\n\nPress Any Key To Go Back To Main Menu...\n\n";
		system("pause > 0");
		system("cls");
		ShowAtmMainMenu();
	}

	static short ReadAtmMainMenuOption()
	{
		short Chose;
		cout << "\t\t\t\t\tEnter Chose [1:6]: ";
		Chose = clsInputValidate::ReadNumberBetween(1, 6, "\t\t\t\t\tInvalid Number :( ,Enter Number [1:6]: ");
		return Chose;
	}

	static void _PerFromAtmMainMenu(enAtmMainMenuOpetion Option)
	{
		switch (Option)
		{
		case enAtmMainMenuOpetion::aShowBalance:
			_ShowBalanceScreen();
			_GoBackToMainMenu();
			break;
		case enAtmMainMenuOpetion::aQuickWithDraw:
			_ShowQuickWithDrawScreen();
			_GoBackToMainMenu();
			break;
		case enAtmMainMenuOpetion::aWithDraw:
			_ShowWithDrawScreen();
			_GoBackToMainMenu();
			break;
		case enAtmMainMenuOpetion::aDeposit:
			_ShowDepositScreen();
			_GoBackToMainMenu();
			break;
		case enAtmMainMenuOpetion::aChangePinCode:
			_ShowChangePinCode();
			_GoBackToMainMenu();
			break;
		case enAtmMainMenuOpetion::aLogOut:
			_ShowLogOutScreen();
			break;
		default:
			_ShowLogOutScreen();
	
		}
	}

public:

	static void ShowAtmMainMenu()
	{
		_DrawScreenHeader("Atm Main Menu");
		cout << "\t\t\t\t\t============================================\n";
		cout << "\t\t\t\t\t[1] Show Balance\n";
		cout << "\t\t\t\t\t[2] Quick  WithDraw\n";
		cout << "\t\t\t\t\t[3] WithDraw\n" ;
		cout << "\t\t\t\t\t[4] Deposit\n" ;
		cout << "\t\t\t\t\t[5] Change PinCod\n" ;
		cout << "\t\t\t\t\t[6] LogOut\n" ;
		cout << "\t\t\t\t\t============================================\n";
		_PerFromAtmMainMenu(enAtmMainMenuOpetion(ReadAtmMainMenuOption()));
	}
};

