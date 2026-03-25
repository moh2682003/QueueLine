#pragma once
#include "clsInputValidate.h";
#include "Global.h"
#include "clsShowAtmMainMenuScreen.h"
#include "clsScreen.h"

class clsShowLoginRegister  : protected clsScreen
{
	static void _Login()
	{
		string AccountNumber, PinCode;
		int RemindLogin = 1;

		bool LoginFailed = false;

		do
		{

			if (LoginFailed)
			{
				cout << "\ninvalid Acc.Number / Password\n";
				cout << "You Have " << (3 - RemindLogin) << "Trails\n";
				RemindLogin++;
			}

			cout << "\nEnter Acc.Number: ";
			AccountNumber = clsInputValidate::ReadString();
			cout << "\nEnter PinCode: ";
			PinCode = clsInputValidate::ReadString();

			CurrentClient = clsAtmSystem::Find(AccountNumber, PinCode);

			LoginFailed = CurrentClient.IsEmpty();

			if (RemindLogin == 4)
			{
				return;
			}

		} while (LoginFailed);
		
		clsShowAtmMainMenuScreen::ShowAtmMainMenu();
	}

public:

	static void ShowLogin()
	{
		_DrawScreenHeader("Login");
		_Login();
	}
};

