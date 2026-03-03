#include <iostream>
#include "clsDateLibrary.h" 

using namespace std;

int main() 
{

    clsDateLibrary Date("29/2/2022");
    clsDateLibrary Date1("35/2/2022");
    clsDateLibrary Date2("31/4/2022");
    clsDateLibrary Date3("2/2/2022");
    clsDateLibrary Date4("29/2/2000");
    clsDateLibrary Date5("25/15/2000");

        cout << Date.IsValidDate() << endl;

        cout << Date1.IsValidDate() << endl;

        cout << Date2.IsValidDate() << endl;

        cout << Date3.IsValidDate() << endl;

        cout << Date4.IsValidDate() << endl;

        cout << Date5.IsValidDate() << endl;


    Date1.Print();
    
    //cout << Date.DiffBetweenDate1AndDate2(Date1);
    system("pause > 0");

    return 0;
}


