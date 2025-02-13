#include <iostream>
#include "reports.cpp"
#include "invmenu.cpp"
#include "cashier.cpp"

using namespace std;

int mainMenu();
void optionCheck(int);


int main(){

int userOption = mainMenu();


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

    while(userChoice <1 || userChoice >5){
    
                cout << "\nPlease enter a valid number 1-4. ";
                cin >> userChoice;
        }

        
        return userChoice;

}






void optionCheck(int userChoice){


switch(userChoice){

    case 1:

    cout << '\n' << setw(15) << ' ' << "You selected item 1\n\n";

    userTransaction();

    break;

    case 2:
    cout <<'\n' << setw(15) << ' ' <<  "You selected item 2\n\n";

    inventoryCheck();

    break;

    case 3:
    cout << '\n' << setw(15) << ' ' << "You selected item 3\n\n";
    reportInfo();

    break;

    case 4:
    cout << '\n' << setw(15) << " " << "You selected item 4\n\n";

    break;


}

  

}