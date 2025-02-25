#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "invmenu.h"


using namespace std;

//ifstream -> you read
//ofstream -> you write

const int MAX_STORAGE = 20;

string bookTitle[MAX_STORAGE];
string isbn[MAX_STORAGE];
string author[MAX_STORAGE];
string dateAdded[MAX_STORAGE];
string qtyOnHand[MAX_STORAGE];
string wholeSale[MAX_STORAGE];
string retail[MAX_STORAGE];


void invMenu(){



    std::ofstream writeFile;
    std::ifstream readFile;

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


void lookUpBook(){
            cout << '\n' << setw(15) << "You selected look Up book\n\n";
}

void addBook(){
            cout << '\n' << setw(15) << "You selected add book\n\n";
vector<int> storageIndex;

 
    for(int i=0; i<MAX_STORAGE; i++){
        if(i>=4 && i<=15){
           bookTitle[i] = "Sigma\n";
        }
        if(bookTitle[i] == ""){
            
            
            cout << "Slot available\n";
            storageIndex.push_back(i);

        }
    cout << bookTitle[i] << i + 1 << endl;




    }




            
}

void editBook(){
            cout << '\n' << setw(15) << "You selected edit book\n\n";
}

void deleteBook(){
            cout << '\n' << setw(15) << "You selected delete  book\n\n";
}