#include <iostream>
#include <iomanip>

using namespace std;



int mainMenu(){

cout << "Choose number 1-4:" << endl; 
cout << "Serendipity Booksellers " << endl;
cout << setw(4)<< " " << "Main Menu" << endl;
cout <<"1.	Cashier Module" << endl;
cout <<"2.	Inventory Database Module" << endl;
cout <<"3.	Report Module" << endl;
cout <<"4.	Exit" << endl;

cout << "Enter your choice. " << endl;

int userChoice;
double userPay;
cin >> userChoice;
cin.ignore();

while(userChoice <=0 || userChoice >=5){

    cout << "\nTry again: ";
    cin >> userChoice;
}


    return userChoice;
}