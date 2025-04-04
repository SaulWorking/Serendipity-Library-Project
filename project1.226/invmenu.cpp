/******************************************************************
** Program: Serendipity Booksellers POS and inventory management software 
** Description: program will help employees sell and manage inventory


** Course: CS226 CRN 32842
** Professor: Huseyin Aygun
** Student: Thien Dinh
** Due Date: 04/6/2025
******************************************************************/


//thank you for fixing this 

#include <iostream>
#include <iomanip>
#include <cstring>
#include "allheaders.h"
using namespace std;


void invMenu(){

    int inventoryChoice{0};
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

void lookUpBook() {

    int bookIndex = -1;
    string bookName = "placeHolder";
        
            cout << "Title of book to look up: ";

                cin.ignore();
            getline(cin, bookName);
 
            bookIndex = findBookIndex(bookName);
                
            if (bookIndex >=0) {
                  // look up book
        
                cout << "\nThe only book matching your title is...\n";
                
                bookIndexInformation(bookIndex);
        
            } else {
                  cout << "Book not in inventory\n\n"; 
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
        if(isEmpty(index)){
        
            //user input variables
            char userInput[51];
            int userQuantity = 0;
            double userPrice = 0.0;

            emptyBookIndex = index;

            cin.ignore();
            cout <<"book title: ";
            
            cin.getline(userInput, 51);
            strUpper(userInput);
            setTitle(userInput, emptyBookIndex);
    
            cout <<"ISBN: ";
            cin.getline(userInput, 14);  
            strUpper(userInput);
            setISBN(userInput, emptyBookIndex);


            cout<< "Author: ";
            cin.getline(userInput, 31);
            strUpper(userInput);
            setAuthor(userInput, emptyBookIndex);


            cout <<"Publisher: ";
            cin.getline(userInput, 31);
            strUpper(userInput);
            setPub(userInput, emptyBookIndex);

            
            cout << "Date: ";
            cin.getline(userInput, 11);
            setDateAdded(userInput, emptyBookIndex);
            
            
            cout << "Quantity: ";
            cin >> userQuantity;
            setQty(userQuantity, emptyBookIndex);
    
            cout << "Wholesale value: ";
            cin >> userPrice;
            setWholesale(userPrice, emptyBookIndex);

            cout << "Retail value: ";
            cin >> userPrice;
            setRetail(userPrice, emptyBookIndex);

            return;
        }
        //check last slot for book availability.
        
        if(isEmpty(19)){
            cout << "Sorry, no space available for new books.\n";
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
    

        cin.ignore();
        getline(cin, bookName);

        bookIndex = findBookIndex(bookName);

        if(bookIndex >=0){
            cout << '\n' << setw(20) << ' ' << "Do you really want to delete this?(Y/N): ";
    
                cin >> user;
                    cin.ignore();

            if(toupper(user) == 'Y'){
                removeBook(bookIndex);
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
        cin >> userEditChoice;
        cin.ignore();

    switch(userEditChoice){
        case 1:
            cout <<"\n Changing title to: ";
            cin.getline(userInput, 51);
            strUpper(userInput);
            setTitle(userInput, index);
            break;
        case 2:
            cout <<"\n Changing ISBN to: ";
            cin.getline(userInput, 14);
            strUpper(userInput);
            setISBN(userInput, index);

            break;
        case 3:
            cout <<"\n Changing author to: ";
            cin.getline(userInput, 31);
            strUpper(userInput);
            setAuthor(userInput, index);

            break;
        case 4:
            cout <<"\n Changing publisher to: ";
            cin.getline(userInput, 31);
            strUpper(userInput);
            setPub(userInput, index);

            break;
         case 5:
            cout <<"\n Changing date added to: ";
            cin.getline(userInput, 11);
            strUpper(userInput);
            setDateAdded(userInput, index);
            break;
         case 6:
            cout <<"\n Changing quantity to: ";
            cin >> userQuantity;
            setQty(userQuantity, index);
            break;
         case 7:
            cout <<"\n Changing wholesale value to: ";
            cin >> userPrice;
            setWholesale(userPrice, index);
            break;
        case 8:
            cout <<"\n Changing retail value to: ";
            cin >> userPrice;
            setRetail(userPrice, index);
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
        while( *(wordToBeUppercase+counter) != '0' && isalpha(*(wordToBeUppercase + counter))){

            *(wordToBeUppercase+counter) = toupper(wordToBeUppercase[counter]);
                counter++;
        }
}

int findBookIndex(string bookWant){
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


        for(int i =0; i <20; i++){
        //general reminder 

            //strstr returns pointer to string or nullptr
            //if statement accepts pointers
            
            //check if input is found in inventory. continue if else.
            if(strstr(invbook[i].Title, bookToBeSearched)){
                strncpy(found, strstr(invbook[i].Title, bookToBeSearched), 51);
                }else{
                    continue;
            }

                //check if substring is empty
            if(found[0] != '\0'){

                //check if substring and book title are valid 
                if(!strcmp(found, invbook[i].Title) && invbook[i].Title[0] != '\0'){

                    bookIndex = i;
                        bookIndexInformation(bookIndex);
                        cout << "\nIs this your book(Y/N)?";
                            cin >> userInput;
                    //if book is intended book exit loop
                        if(isalpha(userInput) && userInput == 'Y' || userInput == 'y'){
                            return bookIndex;
                        }else {
                            //else continue searching
                            cout << "\nNext book...\n\n";

                        }
                }
            }

    }

    //return to zero
    bookIndex = -1;

    return bookIndex;

}


    







/*The lookUpBook function currently requires the user to enter 
                    the full name of the book to search for. 
Modify it so the user only has to enter part of the book title. 
Hint: Use the strstr function to search the title in the database.*/

void bookIndexInformation(const int bookIndex){
    bookInfo(
    invbook[bookIndex].Title, 
    invbook[bookIndex].ISBN,
    invbook[bookIndex].Author,  
    invbook[bookIndex].Publisher, 
    invbook[bookIndex].DateAdded, 
    invbook[bookIndex].QtyOnHand,
    invbook[bookIndex].WholesaleValue, 
    invbook[bookIndex].RetailValue);
}







void setTitle(char *bookName, int bookIndex){
    strncpy(invbook[bookIndex].Title, bookName, 51);
}
void setISBN(char *ISBN, int bookIndex){
    strncpy(invbook[bookIndex].ISBN, ISBN, 14);
}
void setAuthor(char *Author, int bookIndex){
    strncpy(invbook[bookIndex].Author, Author, 31);
}		 
void setPub(char *Publisher, int bookIndex){
    strncpy(invbook[bookIndex].Publisher, Publisher, 31);

}
void setDateAdded(char *DateAdded, int bookIndex){
    strncpy(invbook[bookIndex].DateAdded, DateAdded, 11);
}

void setQty(int bookQuantity, int bookIndex){
    invbook[bookIndex].QtyOnHand = bookQuantity;
}
void setWholesale(double wholesalePrice, int bookIndex){
    invbook[bookIndex].WholesaleValue = wholesalePrice;
} 
void setRetail(double retailPrice, int bookIndex){
    invbook[bookIndex].RetailValue = retailPrice;
}
int isEmpty(int bookIndex){
        //checks for first character of Title at specified book index
    if(invbook[bookIndex].Title[0] == '\0'){
        return true;
    }else{  
        return false;
    }

}
void removeBook(int bookIndex){
    invbook[bookIndex].Title[0] = '\0';
    invbook[bookIndex].ISBN[0] = '\0';
    invbook[bookIndex].Author[0]= '\0';
    invbook[bookIndex].Publisher[0] = '\0';
    invbook[bookIndex].DateAdded[0]= '\0';
    invbook[bookIndex].QtyOnHand = 0;
    invbook[bookIndex].RetailValue = 0.0;
    invbook[bookIndex].WholesaleValue = 0.0;
}

