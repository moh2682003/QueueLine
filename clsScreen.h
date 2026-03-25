#pragma once
#include "Global.h"
#include "clsDateLibrary.h"

using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        system("cls");
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        cout << "\n\t\t\t\t\tClient Name: " << CurrentClient.FullName() << endl;
        cout << "\t\t\t\t\tDate:" << clsDateLibrary::DateToString(clsDateLibrary()) << endl;
        if (Title == "Quick WithDraw Menu" || Title == "With Draw Screen")
            cout << "\t\t\t\t\tTotal Balance: " << CurrentClient.AccountBalance << endl << endl ;

    }

};

