/******************************************************************
** Program: Serendipity Booksellers POS and inventory management software 
** Description: program will help employees sell and manage inventory


** Course: CS226 CRN 32842
** Professor: Huseyin Aygun
** Student: Thien Dinh
** Due Date: 04/27/2025
******************************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
#include "../include/allheaders.h"

//example data
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

/*
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
*/

//Declaring global OBJECT... to be read in
InventoryBook invbook;
BookStorage bookFile;


Menu menuHelper;

int main(){

    

    int mainMenuChoice{0};
    bool exitModule = false;
    
    while(exitModule == false){

     menuHelper.menuOutput("MainMenu");

     std::cin >> mainMenuChoice;

    menuHelper.separateText();
    

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
            std::cout << '\n' << std::setw(15) << ' ' << "Goodbye!\n";

                //close file 
                bookFile.~BookStorage();
                //exit program
                exitModule = true;
                break;
            default:
            std::cout << "Enter a number 1-4\n";
                break;
        }
    }
    return 0;
}
