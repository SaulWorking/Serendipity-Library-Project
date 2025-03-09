#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "invmenu.h"
#include "bookinfo.h"
using namespace std;

//ifstream -> you read
//ofstream -> you writ
const int MAX_STORAGE = 20;

string bookTitle[MAX_STORAGE];
string isbn[MAX_STORAGE];
string author[MAX_STORAGE];
string publisher[MAX_STORAGE];
string dateAdded[MAX_STORAGE];
int qtyOnHand[MAX_STORAGE];
double wholeSale[MAX_STORAGE];
double retail[MAX_STORAGE];




void invMenu(){





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
        cout << "\n" << setw(15) << " " << "Please enter a valid number 1-5: ";
            
            cin >> userChoice;
        }

        invCheck(userChoice);

    return;
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
                break;
        }
    return;
}


//search to check if book is in stock and prints out book info
void lookUpBook(){

    string userChoice; 
    int index = -1;

    cout << '\n' << setw(15) << "You selected look Up book\n\n";
    cout << '\n' << setw(15) << "Title of book: ";

        cin.ignore();
            getline(cin, userChoice);

        for(int i =0; i<MAX_STORAGE; i++){

            if(bookTitle[i] == userChoice){
                index = i;
            }

        }

    if(index != -1 && userChoice != ""){
        bookInfo(bookTitle[index], isbn[index], author[index], publisher[index], dateAdded[index], qtyOnHand[index], wholeSale[index], retail[index]);
    }else{
        cout << '\n' << setw(15) << ' ' << "Book not found.\n";
    }

}

//check if book space is available
//if available add book
//books can have the same title, unfortunately
void addBook(){

    int counter = 0;
    vector<int> indexList;
    
    cout << '\n' << setw(15) << "You selected add book\n\n";

    for(int i=0; i<MAX_STORAGE; i++){
        if(bookTitle[i] == ""){
            indexList.push_back(i);
            counter++;
        }
    }

    if(counter <=0){
        cout << "No more slots available.\n";
        return;
    }else{

        cin.ignore();
        cout <<"book: ";
        getline(cin, bookTitle[indexList[indexList.size() -1]]);

        cout <<"isbn: ";
        getline(cin, isbn[indexList[indexList.size() -1]]);

        cout<< "author: ";
        getline(cin, author[indexList[indexList.size() -1]]);
        
        cout <<"publisher: ";
        getline(cin, publisher[indexList[indexList.size() -1]]);

        cout << "date: ";
        getline(cin,  dateAdded[indexList[indexList.size() -1]]);

        cout << "quantity: ";
        cin >> qtyOnHand[indexList[indexList.size() -1]];

        cout << "wholesale: ";
        cin >> wholeSale[indexList[indexList.size() -1]];

        cout << "retail: ";
        cin >> retail[indexList[indexList.size() -1]];

            indexList.pop_back();
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


    for(int i =0; i<MAX_STORAGE; i++){
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

    cout << "\nWhat do you want to change?\nI.E type the first word of each category to change it: quantity on hand = Quantity\nOption: ";

        getline(cin, userChoice);


    //checks for one of eight categories for book Information

    if(userChoice == "title" || userChoice == "Title"){
	 cout << "\nChange Title of " << bookTitle[index] << " to: ";
        getline(cin, userChoice);
        bookTitle[index] = userChoice;

    }else if(userChoice == "isbn" || userChoice == "ISBN"){
	 cout << "\nChange ISBN of " << bookTitle[index] << " to: ";
        getline(cin, userChoice);
        isbn[index] = userChoice;

    }else if(userChoice == "author" || userChoice == "Author"){
	 cout << "\nChange author of " << bookTitle[index] << " to: ";
        getline(cin, userChoice);
        author[index] = userChoice;

    }else if(userChoice == "publisher" || userChoice == "Publisher"){
	 cout << "\nChange publisher of " << bookTitle[index] << " to: ";
         getline(cin, userChoice);
         isbn[index] = userChoice;

    }else if(userChoice == "date"  || userChoice == "Date"){
	 cout << "\nChange date of " << bookTitle[index] << " to: ";
         getline(cin, userChoice);
         dateAdded[index] = userChoice;

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

//tests for book availability in storage and deletes book
void deleteBook(){
    string userChoice;
    char user;
    int index = -1;

    cout << '\n' << setw(15) << ' ' << "You selected delete book\n\n";
    cout << '\n' << setw(15) << ' ' << "which book will you delete? : ";
    
        cin.ignore();
        getline(cin, userChoice);


        for(int i =0; i<MAX_STORAGE; i++){

            if(bookTitle[i] == userChoice){
                index = i;
                
                bookInfo(bookTitle[index], isbn[index], author[index], publisher[index], dateAdded[index], qtyOnHand[index], wholeSale[index], retail[index]);
                break;
            }
        }
    
        if(index != -1){

            cout << '\n' << setw(20) << ' ' << "Do you really want to delete this?(Y/N): ";
            cin >> user;

            if(user == 'y' || user == 'Y'){
                bookTitle[index] = "";
                isbn[index] = "";
                author[index]= "";
                publisher[index] = "";
                dateAdded[index] = "";
                qtyOnHand[index] = 0;
                wholeSale[index] = 0.0;
                retail[index] = 0.0;  
            }else{
                cout << setw(25) << ' ' << "Book doesnt exist.\n";

                 }
         }
    return;

}
