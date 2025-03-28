/******************************************************************
** Program: Serendipity Booksellers POS and inventory management software 
** Description: program will help employees sell and manage inventory


** Course: CS226 CRN 32842
** Professor: Huseyin Aygun
** Student: Thien Dinh
** Due Date: 03/9/2025
******************************************************************/


#include <iostream>
#include <iomanip>
#include "allheaders.h"


//use  to link the same array between multiple filers...

using namespace std;

void mainMenu(int);
void optionCheck(int);



    
  int qtyOnHand[20] = {40, 35, 50, 25, 20, 45, 30, 15, 10, 12};
  double wholeSale[20] = {12.50, 25.00, 34.5, 30.00, 28.00, 40.00, 35.00, 38.00, 45.00, 50.00};    
  double retail[20] = {30.4, 45.0, 56.7, 50.0, 47.5, 65.0, 55.0, 60.0, 70.0, 80.0};





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
        userChoice =cashier();
        if(-2 == userChoice)
            mainMenu(userChoice);
        break;

        case 2:
        
        userChoice = invMenu();
        if(5 == userChoice)
            mainMenu(userChoice);

        break;

        case 3:
        userChoice = reports();
        if(7 == userChoice)
            mainMenu(userChoice);

        break;

        case 4:
        cout << '\n' << setw(15) << " " << "Goodbye!\n";
        break;


    }

}