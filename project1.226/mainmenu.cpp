#include <iostream>
#include <iomanip>
#include "cashier.h"
#include "invmenu.h"

//#include "reports.cpp"
//#include "invmenu.cpp"
//#include "cashier.cpp"

using namespace std;

void mainMenu(int &);
void optionCheck(int);


int main(){

int userOption{0};

mainMenu(userOption);





    return 0;
}






void mainMenu(int &userChoice){



cout << setw(20) << " " << "Serendipity Booksellers " << endl;
cout << setw(25) << " " << "Main Menu" << "\n\n";
cout << setw(15) << " " << "1.	Cashier Module" << endl;
cout << setw(15) << " " << "2.	Inventory Database Module" << endl;
cout << setw(15) << " " << "3.	Report Module" << endl;
cout << setw(15) << " " << "4.	Exit" << endl;

cout << "\n\n" << setw(15) << ' ' << "Enter your choice: ";

cin >> userChoice;

cout << "\n\n";



       if(userChoice <1 || userChoice >4){

                    cout << "\n\n\n" << setw(15) << " " << "Please enter a valid number 1-4.\n\n\n";

        }

        optionCheck(userChoice);
   

}






void optionCheck(int userChoice){


switch(userChoice){

    case 1:

    cout << '\n' << setw(15) << ' ' << "You selected item 1\n\n\n";

    cashier();

    break;

    case 2:
    cout <<'\n' << setw(15) << ' ' <<  "You selected item 2\n\n\n";

  //  inventoryCheck(userChoice);

    break;

    case 3:
    cout << '\n' << setw(15) << ' ' << "You selected item 3\n\n\n";
  //  reportInfo(userChoice);

    break;

    case 4:
    cout << '\n' << setw(15) << " " << "You selected item 4\n\n\n";

    break;


}

  

}