#include <iostream>
#include "reports.cpp"
#include "invmenu.cpp"
#include "cashier.cpp"

using namespace std;

int mainMenu();
void optionCheck(int);


int main(){

int userOption{0};

userOption = mainMenu();


optionCheck(userOption);



    return 0;
}


















int mainMenu(){

int userChoice;
double userPay;


cout << setw(20) << " " << "Serendipity Booksellers " << endl;
cout << setw(25) << " " << "Main Menu" << endl;
cout << setw(15) << " " << "1.	Cashier Module" << endl;
cout << setw(15) << " " << "2.	Inventory Database Module" << endl;
cout << setw(15) << " " << "3.	Report Module" << endl;
cout << setw(15) << " " << "4.	Exit" << endl;

cout << '\n' << setw(15) << ' ' << "Enter your choice: ";


cin >> userChoice;
cin.ignore();

while(userChoice <=0 || userChoice >=5){

    cout << "\nPlease enter a valid number.";
    cin >> userChoice;
}


    return userChoice;
}







void optionCheck(int userChoice){

if(userChoice == 1)
    userTransaction();
if(userChoice == 2)
    inventoryCheck();
if(userChoice == 3)
    reportInfo();
if(userChoice == 4)
    cout << '\n' << setw(23) << "Bye bye!";

}