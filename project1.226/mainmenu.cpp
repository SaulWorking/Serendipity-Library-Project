/******************************************************************
** Program: Serendipity Booksellers POS and inventory management software 
** Description: program will help employees sell and manage inventory


** Course: CS226 CRN 32842
** Professor: Huseyin Aygun
** Student: Thien Dinh
** Due Date: 04/6/2025
******************************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
#include "allheaders.h"
using namespace std;

//global data
    /*
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
        int bookQtyOnHand[20] =         {40, 35, 50, 25, 20, 45, 30, 15, 20, 12};
    // Wholesale Price 
        double bookWholesaleValue[20] = {12.50, 25.0, 34.5, 30.0, 28.0, 40.0, 35.0, 38.0, 45.0, 50.0};    
    // Retail Price 
        double bookRetailValue[20] =    {30.4, 45.0, 56.7, 50.0, 47.5, 65.0, 55.0, 60.0, 70.0, 80.0};
    */

    //arrays sorted by TITLE, ISBN, AUTHOR, PUBLISHER, DATE ADDED, QUANTITY, PRICE, and RETAIL PRICE
BookData invbook[20] = {
        {"FREEDOM", "0374158460", "JONATHAN FRANZEN", "FARRAR", "03-05-2004", 40, 12.50, 30.4},
    
        {"HEAD FIRST DESIGN PATTERNS", "0596007124", "ELISABETH FREEMAN", "O'REILLY MEDIA", "01-13-2006", 35, 25.00, 45.0},
    
        {"ARDUINO COOKBOOK", "0596802471", "MICHAEL MARGOLIS", "O'REILLY MEDIA", "02-05-2025", 50, 34.5, 56.7},
    
        {"CLEAN CODE", "9780132350884", "ROBERT C. MARTIN", "PRENTICE HALL", "06-04-2008", 25, 30.00, 50.0},
    
        {"THE PRAGMATIC PROGRAMMER", "9780201616224", "ANDREW HUNT", "ADDISON-WESLEY", "02-05-2005", 20, 28.00, 47.5},
    
        {"LEARNING PYTHON", "9781491950357", "MARK LUTZ", "O'REILLY MEDIA", "12-4-2013", 45, 40.00, 65.0},
    
        {"REFACTORING", "9780321125217", "MARTIN FOWLER", "ADDISON-WESLEY", "5-5-2019", 30, 35.00, 55.0},
    
        {"EFFECTIVE JAVA", "9780134494166", "JOSHUA BLOCH", "ADDISON-WESLEY", "03-14-2009", 15, 38.00, 60.0},
    
        {"FLUENT PYTHON", "9781491946008", "LUCIANO RAMALHO", "O'REILLY MEDIA", "05-12-2020", 20, 45.00, 70.0},
    
        {"INTRODUCTION TO THE THEORY OF COMPUTATION", "9780137082073", "MICHAEL SIPSER", "CENGAGE LEARNING", "02-05-2025", 12, 50.00, 80.0}
    };

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