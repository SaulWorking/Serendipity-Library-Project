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
#include "inventory.h"
#include "cashier.h"
#include "invmenu.h"
#include "bookinfo.h"
#include "reports.h"

//use  to link the same array between multiple filers...

using namespace std;

void mainMenu(int);
void optionCheck(int);



 string bookTitle[20] = {"Freedom", "Head First Design Patterns", "Arduino Cookbook", "Clean Code",
    "The Pragmatic Programmer", "Learning Python", "Refactoring","Effective Java", "Fluent Python", 
        "Introduction to the Theory of Computation"};

 string isbn[20] = {"0374158460", "0596007124", "0596802471", "9780132350884", 
    "9780201616224", "9781491950357", "9780321125217", "9780134494166", "9781449355739", "9780137081073"};

  string author[20] = {"Jonathan Franzen", "Elisabeth Freeman", "Michael Margolis", "Robert C. Martin", 
                "Andrew Hunt", "Mark Lutz", "Martin Fowler", "Joshua Bloch","Luciano Ramalho", "Michael Sipser"};

  string publisher[20] = {"Farrar", "O'Reilly Media", "O'Reilly Media", "Prentice Hall",
                                     "Addison-Wesley", "O'Reilly Media", "Addison-Wesley",
                                    "Addison-Wesley", "O'Reilly Media", "Cengage Learning"};

  string dateAdded[20] =   {"03-05-2004", "01-13-2006", "02-05-2025", "06-04-2008", "02-05-2005",
    "12-4-2013", "5-5-2019", "03-14-2009", "05-12-2020", "02-05-2025"};

    
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