/******************************************************************
** Program: Serendipity Booksellers POS and inventory management software 
** Description: program will help employees sell and manage inventory


** Course: CS226 CRN 32842
** Professor: Huseyin Aygun
** Student: Thien Dinh
** Due Date: 03/30/2025
******************************************************************/


//defo fix this

#include <iostream>
#include <iomanip>
#include <cstring>
#include "allheaders.h"
using namespace std;


void invMenu(){

    int inventoryChoice;
    bool exitModule = false;


   while(exitModule == false){
    cout << setw(20) << ' ' << " Serendipity Booksellers" << endl;
    cout << setw(23) << ' ' << "Inventory Database\n\n";
    cout << setw(15) << ' ' << "1.	Look Up a Book"        << endl;
    cout << setw(15) << ' ' << "2.       Add a Book"      << endl;
    cout << setw(15) << ' ' << "3.	Edit a Book's Record"  << endl;
    cout << setw(15) << ' ' << "4.	Delete a Book"         << endl;
    cout << setw(15) << ' ' << "5.	Return to the Main Menu"  << endl;
    cout << '\n' << setw(15) << ' ' << "Enter your choice: ";

        cin >> inventoryChoice;

        switch (inventoryChoice) {
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





//simple choice checking for user Inventory Database options.


//check if book space is available
//if available add book
//books can have the same title, unfortunately
void addBook(){

    //empty book index
    int emptyBookIndex = 0;
    
        cout << '\n' << setw(15) << "You selected add book\n\n";

    //check for empty book index
    for(int index=0; index<20; index++)
        //assign empty slot to book userchoice
        if(bookTitle[index][0] == '\0'){
            
            emptyBookIndex = index;

            cin.ignore();
            cout <<"book title: ";
            cin.getline(bookTitle[emptyBookIndex], 51);
            strUpper(bookTitle[emptyBookIndex]);
    
            cout <<"ISBN: ";
            cin.getline(bookISBN[emptyBookIndex], 14);  
            strUpper(bookISBN[emptyBookIndex]);
    
            cout<< "Author: ";
            cin.getline(bookAuthor[emptyBookIndex], 31);
            strUpper(bookAuthor[emptyBookIndex]);
    
            cout <<"Publisher: ";
            cin.getline(bookPublisher[emptyBookIndex], 31);
            strUpper(bookPublisher[emptyBookIndex]);
    
            cout << "Date: ";
            cin.getline(bookDateAdded[emptyBookIndex], 11);
            
            cout << "Quantity: ";
            cin >> bookQtyOnHand[emptyBookIndex];
    
            cout << "Wholesale value: ";
            cin >> bookWholesaleValue[emptyBookIndex];
    
            cout << "Retail value: ";
            cin >> bookRetailValue[emptyBookIndex];
    

            
            return;
        }
        //check last slot for book availability.
        
        if(bookTitle[19][0] =='\0'){
            cout << "Sorry, no space available for new books.\n";
            return;
        }

}


void lookUpBook() {
    string bookName;
    int bookIndex = -1;
        cout << "Title of book to look up: ";
        
        getline(cin, bookName);
        cin.ignore();

        bookIndex = findBookIndex(bookName);
        
        if (bookIndex >=0) {
          // look up book


          cout << "\n the only book matching your book name is...\n";
          bookIndexInformation(bookIndex);

        } else {
          cout << "Book not in inventory\n\n";
          

        }

}
       


// search to check if book is in
//edit book if book exists
void editBook(){

    string bookName;
    int bookIndex = -1;

    cout << '\n' << setw(15) << "You selected edit book\n\n";
    cout << '\n' << setw(15) << "Title of book to edit: ";

    getline(cin, bookName);   
    cin.ignore();
        bookIndex = findBookIndex(bookName);

    if (bookIndex >=0) {
        // look up book
        cout << "\nYour book is...\n";
        bookIndexInformation(bookIndex);

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
    
        getline(cin, bookName);
        cin.ignore();
        bookIndex = findBookIndex(bookName);
    
        if(bookIndex >=0){

            cout << '\n' << setw(20) << ' ' << "Do you really want to delete this?(Y/N): ";
    

            cin >> user;
            cin.ignore();

            if(toupper(user) == 'Y'){
                bookTitle[bookIndex][0] = '\0';
                bookISBN[bookIndex][0] = '\0';
                bookAuthor[bookIndex][0] = '\0';
                bookPublisher[bookIndex][0] = '\0';
                bookDateAdded[bookIndex][0] = '\0';
                bookQtyOnHand[bookIndex] = 0;
                bookWholesaleValue[bookIndex] = 0.0;
                bookRetailValue[bookIndex] = 0.0;  
            }else{
                cout << setw(25) << ' ' << "Book doesnt exist.\n";

            }
         }  
    return;

}


void editInventoryInput(int index){


    bool exitModule = false;
    int userInput;

    int quantity;
    double cost;


    while(exitModule == false){

        cout << setw(20) << ' ' << " Serendipity Booksellers";
        cout << setw(23) << ' ' << "Inventory Database\n";
        cout << setw(15) << ' ' << "1   ISBN\n";
        cout << setw(15) << ' ' << "2.  Title\n";
        cout << setw(15) << ' ' << "3.	Author\n" ;
        cout << setw(15) << ' ' << "4.	Publisher\n";
        cout << setw(15) << ' ' << "5.	Date Added\n";
        cout << setw(15) << ' ' << "6.	Quantity\n";
        cout << setw(15) << ' ' << "7.	Wholesale price\n" ;
        cout << setw(15) << ' ' << "8.	Retail Price\n";
        cout << setw(15) << ' ' << "9.	Exit\n\n";


        cout << "Which book value do you want to edit? ";
        cin >> userInput;
        cin.ignore();


    switch(userInput){
        case 1:
            cout <<"\n Changing title to: ";
            cin.getline(bookTitle[index], 51);
            strUpper(bookTitle[index]);
            break;
        case 2:
            cout <<"\n Changing ISBN to: ";
            cin.getline(bookISBN[index], 14);
            strUpper(bookISBN[index]);
            break;
        case 3:
            cout <<"\n Changing author to: ";
            cin.getline(bookAuthor[index], 31);
            strUpper(bookAuthor[index]);
            break;
        case 4:
            cout <<"\n Changing publisher to: ";
            cin.getline(bookPublisher[index], 31);
            strUpper(bookPublisher[index]); 
            break;
         case 5:
            cout <<"\n Changing date added to: ";
            cin.getline(bookDateAdded[index], 11);
            strUpper(bookDateAdded[index]);
            break;
         case 6:
            cout <<"\n Changing quantity to: ";
            cin >> quantity;
            bookQtyOnHand[index] = quantity;
            break;
         case 7:
            cout <<"\n Changing wholesale value to: ";
            cin >> cost;
            bookWholesaleValue[index] = cost;
            break;
        case 8:
            cout <<"\n Changing retail value to: ";
            cin >> cost;
            bookRetailValue[index] = cost;
            break;
        case 9:
            exitModule = true;
            cout <<"goodbye!\n";
            break;
        default:
            cout << "\nTry again!\n";
    }   

    }    

}

void strUpper(char * wordToBeUppercase){
        int counter =0;
        while( *(wordToBeUppercase+counter) != '0'){
            *(wordToBeUppercase+counter) = toupper(wordToBeUppercase[counter]);
                counter++;
        }
}

int findBookIndex(string inventoryBookName){

    //i.e input free -> convert to FREE c-string 
    //check for "FREE" substring
    int bookIndex{-1};
    const int maxNameLength = 51;
    
  



    char bookToBeSearched[maxNameLength];
    char * found;
    char userInput{' '};



        //convert userInput to c-string
        strcpy(bookToBeSearched, inventoryBookName.c_str());
        strUpper(bookToBeSearched);
    

    
    for(int i=0; i<20; i++){


        
        found = strstr(bookTitle[i], bookToBeSearched);
        
            //check if substring is valid
        if(found != nullptr){


            //check if substring and book title are valid 
            if(!strcmp(found, bookTitle[i]) && bookTitle[i][0] != '\0'){
                bookIndex = i;
                    bookIndexInformation(bookIndex);
                    cout << "\nIs this your book(Y/N)?\n\n";
                    
                 //if book is intended book exit loop
                cin >> userInput;

                    if(userInput == 'y' || userInput == 'Y'){
                    
                        return bookIndex;

            
                    }else{
                        //else continue searching
                        cout << "\n\nNext book...\n\n";
                        continue;
                    }
            }
        }

    }
    
    return bookIndex;

}




/*The lookUpBook function currently requires the user to enter 
                    the full name of the book to search for. 
Modify it so the user only has to enter part of the book title. 
Hint: Use the strstr function to search the title in the database.*/

void bookIndexInformation(const int bookIndex){
    bookInfo(
    bookTitle[bookIndex], 
    bookISBN[bookIndex],
    bookAuthor[bookIndex],  
    bookPublisher[bookIndex], 
    bookDateAdded[bookIndex], 
    bookQtyOnHand[bookIndex],
    bookWholesaleValue[bookIndex], 
    bookRetailValue[bookIndex]);
}