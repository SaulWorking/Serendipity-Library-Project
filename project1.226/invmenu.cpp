/******************************************************************
** Program: Serendipity Booksellers POS and inventory management software 
** Description: program will help employees sell and manage inventory


** Course: CS226 CRN 32842
** Professor: Huseyin Aygun
** Student: Thien Dinh
** Due Date: 03/9/2025
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

    cout << setw(20) << ' ' << " Serendipity Booksellers" << endl;
    cout << setw(23) << ' ' << "Inventory Database\n\n";
    cout << setw(15) << ' ' << "1.	Look Up a Book"        << endl;
    cout << setw(15) << ' ' << "2.       Add a Book"      << endl;
    cout << setw(15) << ' ' << "3.	Edit a Book's Record"  << endl;
    cout << setw(15) << ' ' << "4.	Delete a Book"         << endl;
    cout << setw(15) << ' ' << "5.	Return to the Main Menu"  << endl;
    cout << '\n' << setw(15) << ' ' << "Enter your choice: ";

        cin >> inventoryChoice;

    while(exitModule == false){


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

    //temporary word to be converted uppersace
    string word("");
    
    cout << '\n' << setw(15) << "You selected add book\n\n";

    //check for empty book index
    for(int index=0; index<20; index++){

        if(bookTitle[index][0] == '\0'){
            
            emptyBookIndex = index;

            cin.ignore();
            cout <<"book title: ";
            cin.getline(bookTitle[emptyBookIndex], 51);
            strUpper(bookTitle[emptyBookIndex]);
    
            cout <<"isbn: ";
            cin.getline(bookISBN[emptyBookIndex], 14);  
            strUpper(bookISBN[emptyBookIndex]);
    
            cout<< "author: ";
            cin.getline(bookAuthor[emptyBookIndex], 31);
            strUpper(bookAuthor[emptyBookIndex]);
    
            cout <<"publisher: ";
            cin.getline(bookPublisher[emptyBookIndex], 31);
            strUpper(bookPublisher[emptyBookIndex]);
    
            cout << "date: ";
            cin.getline(bookDateAdded[emptyBookIndex], 11);
            
            cout << "quantity: ";
            cin >> bookQtyOnHand[emptyBookIndex];
    
            cout << "wholesale: ";
            cin >> bookWholesaleValue[emptyBookIndex];
    
            cout << "retail: ";
            cin >> bookRetailValue[emptyBookIndex];
    
            return;
        }


    }



     

    }

  
    void lookUpBook() {


        string bookName;
        int index = 0;
      
        cout << "You selected Look Up Book." << endl;
        cout << "Title of book to look up: ";
      
        getline(cin, bookName);
      
      //  index = bookIndex(userBook);
      
        if (index > -1) {
          // look up book
    //      displayBook(index);
      
          cout << "Book looked up..." << endl;
        } else {
          cout << "Book not in inventory";
        }
      }
       


// search to check if book is in
//edit book if book exists
void editBook(){

    string userChoice;
    int quantity{0}, index{-1};
    double cost{0.0};

    cout << '\n' << setw(15) << "You selected edit book\n\n";
    cout << '\n' << setw(15) << "Title of book: ";

        cin.ignore();
        getline(cin, userChoice);


    for(int i =0; i<20; i++){
        if(bookTitle[i] == userChoice){
            index = i;
        }
    }

    if(index == -1 || userChoice == ""){
        cout << "Book is unavailable";
        return;

    }else{
        cout << '\n';
        bookInfo(bookTitle[index], bookISBN[index], bookAuthor[index], bookPublisher[index], bookDateAdded[index], bookQtyOnHand[index], bookWholesaleValue[index], bookRetailValue[index]);

    }



        readInput(index);

    //checks for one of eight categories for book Information

}


//tests for book availability in storage and deletes book
void deleteBook(){
    string userChoice;
    char user;
    int index = -1;

    cout << '\n' << setw(15) << ' ' << "You selected delete book\n\n";
    cout << '\n' << setw(15) << ' ' << "which book will you delete? : ";
    
        cin.ignore();
        getline(cin, userChoice);


        for(int i =0; i<20; i++){

            if(bookTitle[i] == userChoice){
                index = i;
                
                bookInfo(bookTitle[index], bookISBN[index], bookAuthor[index], bookPublisher[index], bookDateAdded[index], bookQtyOnHand[index], bookWholesaleValue[index], bookRetailValue[index]);
                break;
            }
        }
    
        if(index != -1){

            cout << '\n' << setw(20) << ' ' << "Do you really want to delete this?(Y/N): ";
            cin >> user;


            if(toupper(user) == 'Y'){
                bookTitle[index][0] = '\0';
                bookISBN[index][0] = '\0';
                bookAuthor[index][0] = '\0';
                bookPublisher[index][0] = '\0';
                bookDateAdded[index][0] = '\0';
                bookQtyOnHand[index] = 0;
                bookWholesaleValue[index] = 0.0;
                bookRetailValue[index] = 0.0;  
            }else{
                cout << setw(25) << ' ' << "Book doesnt exist.\n";

            }
         }
    return;

}


void readInput(int index){

    string userChoice;

    int quantity;
    double cost;

    cout << "\nWhat do you want to change?\nI.E type the first word of each category to change it: quantity on hand = Quantity\nOption: ";
    getline(cin, userChoice);

    if(userChoice == "title" || userChoice == "Title"){
	 cout << "\nChange Title of " << bookTitle[index] << " to: ";

        cin.getline(bookTitle[index], 51);
        strUpper(bookTitle[index]);


    }else if(userChoice == "isbn" || userChoice == "ISBN"){
	 cout << "\nChange ISBN of " << bookTitle[index] << " to: ";
    
        cin.getline(bookISBN[index], 14);
        strUpper(bookISBN[index]);

    }else if(userChoice == "author" || userChoice == "Author"){
	 cout << "\nChange author of " << bookTitle[index] << " to: ";
        cin.getline(bookAuthor[index], 31);
        strUpper(bookAuthor[index]);


    }else if(userChoice == "publisher" || userChoice == "Publisher"){
	 cout << "\nChange publisher of " << bookTitle[index] << " to: ";
         cin.getline(bookPublisher[index], 31);
         strUpper(bookPublisher[index]); 

    }else if(userChoice == "date"  || userChoice == "Date"){
	 cout << "\nChange date of " << bookTitle[index] << " to: ";
         cin.getline(bookDateAdded[index], 11);
         strUpper(bookDateAdded[index]);

    }else if(userChoice == "quantity" || userChoice == "Quantity"){
	 cout << "\nChange Qunatity of " << bookTitle[index] << " to: ";
         cin >> quantity;
         bookQtyOnHand[index] = quantity;

    }else if(userChoice == "wholesale" || userChoice == "Wholesale"){
	 cout << "\nChange Wholesale value of " << bookTitle[index] << " to: ";
        cin >> cost;
        bookWholesaleValue[index] = cost;

    }else if(userChoice == "retail" || userChoice == "Retail"){
	 cout << "\nChange Retail Value of " << bookTitle[index] << " to: ";
        cin >> cost;
        bookRetailValue[index] = cost;
    }else{
        cout << "\nRetry.\n";
    }
}

void strUpper(char * wordy){

        int counter =0;


        while( *(wordy+counter) != '0'){


            *(wordy+counter) = toupper(wordy[counter]);

  
                counter++;

        }
           }

