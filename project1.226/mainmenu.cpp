#include <iostream>
#include <iomanip>
#include "cashier.h"
#include "invmenu.h"
#include "bookinfo.h"
#include "reports.h"
using namespace std;

void mainMenu(int);
void optionCheck(int);


int main(){
    int userOption{0};
    mainMenu(userOption);
    return 0;
}

//function may be used later

void mainMenu(int userChoice){
    cout << "\n\n\n";
    cout << setw(20) << " " << "Serendipity Booksellers " << endl;
    cout << setw(25) << " " << "Main Menu" << "\n\n";
    cout << setw(15) << " " << "1.	Cashier Module" << endl;
    cout << setw(15) << " " << "2.	Inventory Database Module" << endl;
    cout << setw(15) << " " << "3.	Report Module" << endl;
    cout << setw(15) << " " << "4.	Exit" << endl;
    cout << "\n\n" << setw(15) << ' ' << "Enter your choice: ";
        cin >> userChoice;
    cout << "\n\n";
    while(userChoice < 1 || userChoice > 4){
            cout << "\n" << setw(15) << " " << "Please enter a valid number 1-4: ";
                cin >> userChoice; 
        }
            optionCheck(userChoice);
}



//this function makes it easier to manage userChoices and makes it easier to read (for me)
void optionCheck(int userChoice){

    switch(userChoice){

        case 1:
        cashier();
        break;

        case 2:
        invMenu();
        break;

        case 3:
        reports();
        break;

        case 4:
        cout << '\n' << setw(15) << " " << "Goodbye!\n";
        break;


    }

}