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

// Book titles - 20 rows, 51 characters per title
    char bookTitle[20][51] = {
        "FREEDOM", "HEAD FIRST DESIGN PATTERNS", "ARDUINO COOKBOOK", "CLEAN CODE",
        "THE PRAGMATIC PROGRAMMER", "LEARNING PYTHON", "REFACTORING", "EFFECTIVE JAVA",
        "FLUENT PYTHON", "INTRODUCTION TO THE THEORY OF COMPUTATION"
    };

    // ISBN numbers - 20 rows, 11 characters per ISBN
    char isbn[20][14] = {
        "0374158460", "0596007124", "0596802471", "9780132350884", 
        "9780201616224", "9781491950357", "9780321125217", "9780134494166", 
        "9781449355739", "9780137082073"
    };

    // Author names - 20 rows, 31 characters per author
    char author[20][31] = {
        "JONATHAN FRANZEN", "ELISABETH FREEMAN", "MICHAEL MARGOLIS", "ROBERT C. MARTIN", 
        "ANDREW HUNT", "MARK LUTZ", "MARTIN FOWLER", "JOSHUA BLOCH", "LUCIANO RAMALHO", 
        "MICHAEL SIPSER"
    };

    // Publisher names - 20 rows, 31 characters per publisher
    char publisher[20][31] = {
        "FARRAR", "O'REILLY MEDIA", "O'REILLY MEDIA", "PRENTICE HALL",
        "ADDISON-WESLEY", "O'REILLY MEDIA", "ADDISON-WESLEY", "ADDISON-WESLEY", 
        "O'REILLY MEDIA", "CENGAGE LEARNING"
    };

    // Date Added - 20 rows, 11 characters per date
    char dateAdded[20][11] = {
        "03-05-2004", "01-13-2006", "02-05-2025", "06-04-2008", "02-05-2005",
        "12-4-2013", "5-5-2019", "03-14-2009", "05-12-2020", "02-05-2025"
    };
   

  // Quantity  
  int qtyOnHand[20] = {40, 35, 50, 25, 20, 45, 30, 15, 20, 12};
  // Wholesale Price 
  double wholeSale[20] = {12.50, 25.00, 34.5, 30.00, 28.00, 40.00, 35.00, 38.00, 45.00, 50.00};    
  // Retail Price 
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
