/******************************************************************
** Program: Serendipity Booksellers POS and inventory management software 
** Description: program will help employees sell and manage inventory


** Course: CS226 CRN 32842
** Professor: Huseyin Aygun
** Student: Thien Dinh
** Due Date: 04/27/2025
******************************************************************/
using namespace std;

#include <iostream>
#include <iomanip>
#include <cstring>
#include "../include/headers.h"

void invMenu(){
    int inventoryChoice{0};
    bool exitModule = false;
    
   while(exitModule == false){
    menuHelper.menuOutput("Inventory"); 
    cin >> inventoryChoice;
        
    menuHelper.separateText();
        switch (inventoryChoice){
            case 1:
              lookUpBook();
              break;
            case 2:
              addBook();
              break;
            case 3:
              editBook();
              break;
            case 4:
              deleteBook();
              break;
            case 5:
              exitModule = true;
              break;
            default:
            cout << "Please enter a number in the range 1-5" << endl;
              break;
            }
    }
}

void lookUpBook() {
    int bookIndex = -1;
    string bookName;
        
    cout << "Title of book to look up: ";

    cin.ignore();
    getline(cin, bookName);
        menuHelper.separateText();
            bookIndex = findBookIndex(bookName);
        if (bookIndex >=0) {
            cout << "\n\nThe only book matching your title is...\n\n";
            invbook.bookIndexInformation();
            cout << '\n';
        } else {
            cout << "Book not in inventory\n\n"; 
        }
}

//simple choice checking for user Inventory Database options.

//check if book space is available
//if available add book
//books can have the same title, unfortunately

//make this function shorter soon
void addBook() {
    double priceInput =0.0;
    int quantityInput =0;
    char userInput[51];
    bool writeCheck = false;
    cout << "\nAdding Book...\n" << endl;
    cout << "\nBooks in storage: " << bookFile.storageSize() << endl;

    for (int i = 0; i < bookFile.storageSize(); i++) {
        bookFile.bookRead(invbook, i);

        if (invbook.isEmpty()){

            cin.ignore();
            cout << "ISBN: ";
            cin.getline(userInput, 14);
            menuHelper.separateText();
            strUpper((userInput));
            invbook.setISBN(userInput);
            
            cout << "Title: ";
            cin.getline(userInput, 51);
            menuHelper.separateText();
            strUpper((userInput));
            invbook.setTitle(userInput);
    
            cout << "Author: ";
            cin.getline(userInput, 31);
            menuHelper.separateText();
            strUpper((userInput));
            invbook.setAuthor(userInput);
    
            cout << "Publisher: ";
            cin.getline(userInput, 31);
            menuHelper.separateText();
            strUpper((userInput));
            invbook.setPub(userInput);
    
            cout << "Date: ";
            cin.getline(userInput, 11);
            menuHelper.separateText();
            invbook.setDateAdded(userInput);
    
            cout << "Quantity: ";
            cin >> quantityInput;
            menuHelper.separateText();
            cin.ignore();
            invbook.setQty(quantityInput);
    
            cout << "Wholesale cost: ";
            cin >> priceInput;
            menuHelper.separateText();
            cin.ignore();
            invbook.setWholesale(priceInput);
    
            cout << "Retail cost: ";
            cin >> priceInput;
            menuHelper.separateText();
            cin.ignore();
            invbook.setRetail(priceInput);
            
        if((priceInput > -1 && priceInput <2147483647) && (quantityInput > -1) && (userInput[0] != '\0')){
        writeCheck = true;
        }


        
    //https://stackoverflow.com/questions/38607754/how-to-force-file-flushing

            if(writeCheck){
                bookFile.bookWrite(invbook);
            }else{
                invbook.removeBook();
                cout << "Failure to write...\n";
            }
            return;
        
        }
    }


    if(bookFile.storageSize() < 20){
        cin.ignore();

        cout << "ISBN: ";
        cin.getline(userInput, 14);
        menuHelper.separateText();
        strUpper((userInput));
        invbook.setISBN(userInput);
        
        cout << "Title: ";
        cin.getline(userInput, 51);
        menuHelper.separateText();
        strUpper((userInput));
        invbook.setTitle(userInput);

        cout << "Author: ";
        cin.getline(userInput, 31);
        menuHelper.separateText();
        strUpper((userInput));
        invbook.setAuthor(userInput);

        cout << "Publisher: ";
        cin.getline(userInput, 31);
        menuHelper.separateText();
        strUpper((userInput));
        invbook.setPub(userInput);

        cout << "Date: ";
        cin.getline(userInput, 11);
        menuHelper.separateText();
        invbook.setDateAdded(userInput);

        cout << "Quantity: ";
        cin >> quantityInput;
        menuHelper.separateText();
        cin.ignore();
        invbook.setQty(quantityInput);

        cout << "Wholesale cost: ";
        cin >> priceInput;
        menuHelper.separateText();
        cin.ignore();
        invbook.setWholesale(priceInput);

        cout << "Retail cost: ";
        cin >> priceInput;
        menuHelper.separateText();
        cin.ignore();
        invbook.setRetail(priceInput);
    //https://stackoverflow.com/questions/37034247/ofstream-creating-file-but-not-writing-to-it-in-c
    
    if((priceInput > -1 && priceInput <2147483647) && (quantityInput > -1) && (userInput[0] != '\0')){
        writeCheck = true;
        }

    //https://stackoverflow.com/questions/38607754/how-to-force-file-flushing

            if(writeCheck){
                bookFile.bookWrite(invbook);
            }else{
                invbook.removeBook();
                cout << "Failure to write...\n";
            }
            return;
    }
}


// search to check if book is in
//edit book if book exists
void editBook(){
    string bookName;
    int bookIndex = -1;

    cout << '\n' << setw(15) << "You selected edit book\n\n";
    cout << '\n' << setw(15) << "Title of book to edit: ";

    cin.ignore();
    getline(cin, bookName);   
    menuHelper.separateText();
        bookIndex = findBookIndex(bookName);

    if (bookIndex >=0) {
        // look up book
        cout << "\nYour book is...\n";

        invbook.bookIndexInformation();
        editInventoryInput(bookIndex);
    } else {
        cout << "Book not in inventory\n\n";
    }
     //checks for one of eight categories for book Information 
}

//tests for book availability in storage and deletes book
void deleteBook(){
    string bookName;
    char user;
    int bookIndex = -1;

    cout << '\n' << setw(15) << ' ' << "You selected delete book\n\n";
    cout << '\n' << setw(15) << ' ' << "which book will you delete? : ";
    
    cin.ignore();
        getline(cin, bookName);
        menuHelper.separateText();

            bookIndex = findBookIndex(bookName);

        if(bookIndex >=0){
            cout << '\n' << setw(20) << ' ' << "Do you really want to delete this?(Y/N): ";
            cin >> user;
                cin.ignore();

            if(toupper(user) == 'Y'){
                invbook.removeBook();
                // at book Index and then Write to file
                //book Index Byte
                bookFile.bookWrite(invbook, bookIndex);
            }else{
                cout << setw(25) << ' ' << "Book doesnt exist.\n";
            }
         }  
    return;
}

void editInventoryInput(int index){
    char userInput[51];
    int userQuantity = 0;
    int userEditChoice = 0;
    double userPrice = 0.0;
    bool exitModule = false;
    bool writeCheck = false;

    while(exitModule == false){
        menuHelper.menuOutput("InventoryEdit");
        invbook.bookIndexInformation();

        cout << "Which book value do you want to edit? ";
        cin >> userEditChoice;
        menuHelper.separateText();
        cin.ignore();

    switch(userEditChoice){
        case 1:
        cout <<"\n Changing TITLE to: ";
            cin.getline(userInput, 51);
            strUpper(userInput);
            menuHelper.separateText();
            invbook.setTitle(userInput);      
            if(userInput[0] != '\0'){writeCheck = true;}
    
            break;
        case 2:
        cout <<"\n Changing ISBN to: ";
            cin.getline(userInput, 14);
            strUpper(userInput);
            menuHelper.separateText();
            invbook.setISBN(userInput);
            if(userInput[0] != '\0'){writeCheck = true;}

            break;
        case 3:
        cout <<"\n Changing AUTHOR to: ";
            cin.getline(userInput, 31);
            strUpper(userInput);
            menuHelper.separateText();
            invbook.setAuthor(userInput);
            if(userInput[0] != '\0'){writeCheck = true;}

            break;
        case 4:
        cout <<"\n Changing DATE to: ";
            cin.getline(userInput, 11);
            strUpper(userInput);
            menuHelper.separateText();
            invbook.setDateAdded(userInput); 
            if(userInput[0] != '\0'){writeCheck = true;}

            break;
         case 5:
         cout <<"\n Changing PUBLISHER added to: ";
            cin.getline(userInput, 31);
            strUpper(userInput);
            menuHelper.separateText();
            invbook.setPub(userInput);
            if(userInput[0] != '\0'){writeCheck = true;}

            break;
         case 6:
         cout <<"\n Changing QUANTITY to: ";
            cin >> userQuantity;
            menuHelper.separateText();
            invbook.setQty(userQuantity);
                if(userQuantity > -1){writeCheck = true;}

            break;
         case 7:
         cout <<"\n Changing WHOLESALE value to: ";
            cin >> userPrice;
            menuHelper.separateText();
            invbook.setWholesale(userPrice);
            if(userPrice > -1 && userPrice <2147483647){writeCheck = true;}

            break;
        case 8:
            cout <<"\n Changing RETAIL value to: ";
            cin >> userPrice;
            menuHelper.separateText();
            invbook.setRetail(userPrice);
            if(userPrice > -1 && userPrice <2147483647){writeCheck = true;}

            break;
        case 9:
        if(writeCheck){
            bookFile.bookWrite(invbook, index);
        }else{
            invbook.removeBook();
            cout << "Failure to write...\n";
        }

        exitModule = true;
        cout <<"goodbye!\n";
            break;
        default:
        cout << "\nTry again!\n";
    }   
}

            
//https://stackoverflow.com/questions/38607754/how-to-force-file-flushing



}

void strUpper(char * wordToBeUppercase){
        int counter =0;
        while( *(wordToBeUppercase+counter) != '0' &&  isalpha(*(wordToBeUppercase + counter))){
            *(wordToBeUppercase+counter) =  toupper(wordToBeUppercase[counter]);
                counter++;
        }
}

int findBookIndex(string bookWant){
    //prepare bookfile for operation

    //i.e input free -> convert to FREE c-string 
    //check for "FREE" substring
        int bookIndex{-1};
        char bookToBeSearched[51];
        char found[51];
        char userInput{' '};
        //covert userInput to c-string 
        //convert to uppercase
        //general tip-> use strncpy to prevent segfaults/something similar

        strncpy(bookToBeSearched, bookWant.c_str(), 51);
        strUpper(bookToBeSearched);

        //ending byte

        cout << "\nBooks in storage: " << bookFile.storageSize() << endl;
        for(int i =0; i <bookFile.storageSize();i++){
        
            bookFile.bookRead(invbook, i);

            if(invbook.bookMatch(bookToBeSearched)){
                strncpy(found,  strstr(invbook.getTitle(), bookToBeSearched), 51);
            }else{
            
                continue;
            }

            if(found[0] != '\0'){
                //check if substring and book title are valid 
                if(!strcmp(found, invbook.getTitle()) && invbook.getTitle()[0] != '\0'){
                    bookIndex = i;

                        invbook.bookIndexInformation();
                        cout << "\nIs this your book(Y/N)?";
                        cin >> userInput;
                            menuHelper.separateText();
                    //if book is intended book exit loop
                        if((isalpha(userInput) && userInput == 'Y') ||(userInput == 'y')){
                            return bookIndex;
                        }else {
                            //else continue searching
                            cout << "\nNext book...\n\n";
                        }
                }    
        }
    }
    bookIndex = -1;
    return bookIndex;
}    //premature check