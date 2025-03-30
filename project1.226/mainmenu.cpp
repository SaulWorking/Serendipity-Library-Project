/******************************************************************
** Program: Serendipity Booksellers POS and inventory management software 
** Description: program will help employees sell and manage inventory


** Course: CS226 CRN 32842
** Professor: Huseyin Aygun
** Student: Thien Dinh
** Due Date: 03/30/2025
******************************************************************/


#include <iostream>
#include <iomanip>
#include "allheaders.h"
using namespace std;


// Book titles - 20 rows, 51 characters per title
    char bookTitle[20][51] = {
        "FREEDOM", "HEAD FIRST DESIGN PATTERNS", "ARDUINO COOKBOOK", "CLEAN CODE",
        "THE PRAGMATIC PROGRAMMER", "LEARNING PYTHON", "REFACTORING", "EFFECTIVE JAVA",
        "FLUENT PYTHON", "INTRODUCTION TO THE THEORY OF COMPUTATION"
    };

// ISBN numbers - 20 rows, 11 characters per ISBN
    char bookISBN[20][14] = {
        "0374158460", "0596007124", "0596802471", "9780132350884", 
        "9780201616224", "9781491950357", "9780321125217", "9780134494166", 
        "9781449355739", "9780137082073"
    };

// Author names - 20 rows, 31 characters per author
    char bookAuthor[20][31] = {
        "JONATHAN FRANZEN", "ELISABETH FREEMAN", "MICHAEL MARGOLIS", "ROBERT C. MARTIN", 
        "ANDREW HUNT", "MARK LUTZ", "MARTIN FOWLER", "JOSHUA BLOCH", "LUCIANO RAMALHO", 
        "MICHAEL SIPSER"
    };

// Publisher names - 20 rows, 31 characters per publisher
    char bookPublisher[20][31] = {
        "FARRAR", "O'REILLY MEDIA", "O'REILLY MEDIA", "PRENTICE HALL",
        "ADDISON-WESLEY", "O'REILLY MEDIA", "ADDISON-WESLEY", "ADDISON-WESLEY", 
        "O'REILLY MEDIA", "CENGAGE LEARNING"
    };

// Date Added - 20 rows, 11 characters per date
    char bookDateAdded[20][11] = {
        "03-05-2004", "01-13-2006", "02-05-2025", "06-04-2008", "02-05-2005",
        "12-4-2013", "5-5-2019", "03-14-2009", "05-12-2020", "02-05-2025"
    };
   

// Quantity  
     int bookQtyOnHand[20] = {40, 35, 50, 25, 20, 45, 30, 15, 20, 12};
// Wholesale Price 
     double bookWholesaleValue[20] = {12.50, 25.00, 34.5, 30.00, 28.00, 40.00, 35.00, 38.00, 45.00, 50.00};    
// Retail Price 
     double bookRetailValue[20] = {30.4, 45.0, 56.7, 50.0, 47.5, 65.0, 55.0, 60.0, 70.0, 80.0};




int main(){

    

    int mainMenuChoice{0};
    bool exitModule = false;



//calling functions was harder to visualize so i used a for loop instead

    while(exitModule == false){
    cout << "\n\n\n";
    cout << setw(20) << ' ' << "Serendipity Booksellers " << endl;
    cout << setw(25) << ' ' << "Main Menu" << "\n\n";
    cout << setw(15) << ' ' << "1.	Cashier Module" << endl;
    cout << setw(15) << ' ' << "2.	Inventory Database Module" << endl;
    cout << setw(15) << ' ' << "3.	Report Module" << endl;
    cout << setw(15) << ' ' << "4.	Exit" << endl;
    cout << "\n\n" << setw(15) << ' ' << "Enter your choice: ";
    cin >> mainMenuChoice;

        switch(mainMenuChoice){
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
                cout << '\n' << setw(15) << ' ' << "Goodbye!\n";
                exitModule = true;
                break;
            default:
                cout << "Enter a number 1-4\n";
                break;
        }
    }
    return 0;

}




