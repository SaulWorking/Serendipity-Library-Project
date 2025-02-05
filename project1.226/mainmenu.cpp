#include <iostream>
#include "cashier.cpp"
#include "reports.cpp"
#include "invmenu.cpp"
#include "bookinfo.cpp"

using namespace std;


void mainMenu(){

cout << "Choose number 1-4:" << endl; 
cout << "Serendipity Booksellers Main Menu" << endl;
cout <<"1.	Cashier Module" << endl;
cout <<"2.	Inventory Database Module" << endl;
cout <<"3.	Report Module" << endl;
cout <<"4.	Exit" << endl;






int userChoice;
double userPay;
cin >> userChoice;
cin.ignore();
switch(userChoice){

    case 1:

   userTransaction();

        break;
    case 2:

    inventoryCheck();
        break;
    case 3:

    reportInfo();
        break;
    case 4:

    cout <<"\nExiting the program...";
        break;
    default:

    cout << "Restart. "<<endl;

}


    return;
}