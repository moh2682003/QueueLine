#pragma once
#include "clsScreen.h"
 
class clsChangePinCodeScreen : clsScreen
{
public:
	static void ShowChangePinScreen()
	{
		_DrawScreenHeader("Change Pin Code");

		int RemindTrail = 1;
		string OldPinCode,NewPinCode;


		cout << "Enter Old PinCode: ";
		cin >> OldPinCode;

		while (OldPinCode != CurrentClient.PinCode)
		{
			cout << "Wrong PinCode , Try Again";
			RemindTrail++;
			cout << "Enter Old PinCode: ";
			cin >> OldPinCode;

			if (RemindTrail == 3)
			{
				cout << "\n\nExceeded PIN attempts\n";
				cout << "Card Blocked/Locked\n";
				exit(1);
			}
		}
		
		cout << "Enter New PinCode: ";
		cin >> NewPinCode;

		CurrentClient.setPinCode(NewPinCode);
		CurrentClient.Save();
		cout << "Successful Change :-)\n";
	}
};


