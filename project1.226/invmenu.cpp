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
#include <cstring>
#include "allheaders.h"
using namespace std;


int invMenu(){


    int userChoice;

    cout << setw(20) << " " << " Serendipity Booksellers" << endl;
    cout << setw(23) << " " << "Inventory Database\n\n";
    cout << setw(15) << " " << "1.	Look Up a Book"        << endl;
    cout << setw(15) << " " << "2.       Add a Book"      << endl;
    cout << setw(15) << " " << "3.	Edit a Book's Record"  << endl;
    cout << setw(15) << " " << "4.	Delete a Book"         << endl;
    cout << setw(15) << " " << "5.	Return to the Main Menu"  << endl;
    cout << '\n' << setw(15) << " " << "Enter your choice: ";

        cin >> userChoice;



    while(userChoice <1 || userChoice >5){
        cout << '\n' << "Please enter a valid number 1-5: ";
        

            cin >> userChoice;

        }

        invCheck(userChoice);

    return userChoice;
}

//simple choice checking for user Inventory Database options.
void invCheck(int userChoice){
    switch(userChoice){

            case 1:
        lookUpBook(); 
        invMenu();
                break;
            case 2:
        addBook();
        invMenu();
                break;
            case 3:
        editBook();
        invMenu();
                break;
            case 4:
        deleteBook();
        invMenu();
                break;
            case 5:
		cout << "\nExiting...\n";
    }
    return;
}


//search to check if book is in stock and prints out book info
void lookUpBook(){

    char userChoice[51];
    int index = -1;
    

    cout << '\n' << setw(15) << "You selected look Up book\n\n";
    cout << '\n' << setw(15) << "Title of book: ";

            cin.ignore();
            cin.getline(userChoice, 51);
            strUpper(userChoice);


        

        for(int i =0; i<20; i++){

            
            if(strstr(bookTitle[i], userChoice) == userChoice){
                index = i;

            }

        }


    if(index != -1){
        bookInfo(bookTitle[index], isbn[index], author[index], publisher[index], dateAdded[index], qtyOnHand[index], wholeSale[index], retail[index]);
    }else{
        cout << '\n' << setw(15) << ' ' << "Book not found.\n";
    }



}




//check if book space is available
//if available add book
//books can have the same title, unfortunately
void addBook(){


    //check for empty slots
    int counter = 0;

    //empty book index
    int emptyBookSpace = -1;

    //temporary word to be converted uppersace
    string word("");
    
    cout << '\n' << setw(15) << "You selected add book\n\n";

    

    //check for empty book index
    for(int index=0; index<20; index++){


        if(bookTitle[index][0] == '\0'){
            
            emptyBookSpace = index;

            counter++;
        }


    }

    if(counter <=0){
        cout << "No more slots available.\n";
        return;
    }else{

        cin.ignore();

        cout <<"book title: ";

        cin.getline(bookTitle[emptyBookSpace], 51);
        strUpper(isbn[emptyBookSpace]);


        cout <<"isbn: ";

        cin.getline(isbn[emptyBookSpace], 31);  
        strUpper(isbn[emptyBookSpace]);

        cout<< "author: ";

        cin.getline(author[emptyBookSpace], 31);
        strUpper(isbn[emptyBookSpace]);

        cout <<"publisher: ";

        cin.getline(publisher[emptyBookSpace], 31);
        strUpper(isbn[emptyBookSpace]);


        cout << "date: ";
        cin.getline(dateAdded[emptyBookSpace], 11);



        
        cout << "quantity: ";
        cin >> qtyOnHand[emptyBookSpace];

        while(qtyOnHand[emptyBookSpace] < 0){
            
            cout << "quantity greater than -1: ";
            cin >> qtyOnHand[emptyBookSpace];


        }



        cout << "wholesale: ";
        cin >> wholeSale[emptyBookSpace];

        while(qtyOnHand[emptyBookSpace] < 0){
            
            cout << "quantity greater than -1: ";
            cin >> wholeSale[emptyBookSpace];


        }
        cout << "retail: ";
        cin >> retail[emptyBookSpace];


        while(qtyOnHand[emptyBookSpace] < 0){
            
            cout << "quantity greater than -1: ";
            cin >> retail[emptyBookSpace];


        }


    }


    return;        
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
        bookInfo(bookTitle[index], isbn[index], author[index], publisher[index], dateAdded[index], qtyOnHand[index], wholeSale[index], retail[index]);

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
                
                bookInfo(bookTitle[index], isbn[index], author[index], publisher[index], dateAdded[index], qtyOnHand[index], wholeSale[index], retail[index]);
                break;
            }
        }
    
        if(index != -1){

            cout << '\n' << setw(20) << ' ' << "Do you really want to delete this?(Y/N): ";
            cin >> user;

          

            if(toupper(user) == 'Y'){
                bookTitle[index][0] = '\0';
                isbn[index][0] = '\0';
                author[index][0] = '\0';
                publisher[index][0] = '\0';
                dateAdded[index][0] = '\0';
                qtyOnHand[index] = 0;
                wholeSale[index] = 0.0;
                retail[index] = 0.0;  
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
    
        cin.getline(isbn[index], 14);
        strUpper(isbn[index]);

    }else if(userChoice == "author" || userChoice == "Author"){
	 cout << "\nChange author of " << bookTitle[index] << " to: ";
        cin.getline(author[index], 31);
        strUpper(author[index]);


    }else if(userChoice == "publisher" || userChoice == "Publisher"){
	 cout << "\nChange publisher of " << bookTitle[index] << " to: ";
         cin.getline(publisher[index], 31);
         strUpper(publisher[index]); 

    }else if(userChoice == "date"  || userChoice == "Date"){
	 cout << "\nChange date of " << bookTitle[index] << " to: ";
         cin.getline(dateAdded[index], 11);
         strUpper(dateAdded[index]);

    }else if(userChoice == "quantity" || userChoice == "Quantity"){
	 cout << "\nChange quantity of " << bookTitle[index] << " to: ";
         cin >> quantity;
         qtyOnHand[index] = quantity;

    }else if(userChoice == "wholesale" || userChoice == "Wholesale"){
	 cout << "\nChange Wholesale value of " << bookTitle[index] << " to: ";
        cin >> cost;
        wholeSale[index] = cost;

    }else if(userChoice == "retail" || userChoice == "Retail"){
	 cout << "\nChange ISBN of " << bookTitle[index] << " to: ";
        cin >> cost;
        retail[index] = cost;
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
