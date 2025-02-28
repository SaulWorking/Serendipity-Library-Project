#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "invmenu.h"
#include "bookinfo.h"

using namespace std;

//ifstream -> you read
//ofstream -> you write

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

    if(index != -1 )
        bookInfo(bookTitle[index], isbn[index], author[index], publisher[index], dateAdded[index], qtyOnHand[index], wholeSale[index], retail[index]);


}

/*
string bookTitle[MAX_STORAGE];
string isbn[MAX_STORAGE];
string author[MAX_STORAGE];
string publisher[MAX_STORAGE];
string dateAdded[MAX_STORAGE];
int qtyOnHand[MAX_STORAGE];
double wholeSale[MAX_STORAGE];
double retail[MAX_STORAGE];
*/
void addBook(){
            cout << '\n' << setw(15) << "You selected add book\n\n";

int counter = 0;
vector<int> indexList;
 
    for(int i=0; i<MAX_STORAGE; i++){

        if(bookTitle[i] == ""){
            

            indexList.push_back(i);
            counter++;
            cout << "Slot available at index " << i << endl;
 
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
        cout << "date: ";
        getline(cin,  dateAdded[indexList[indexList.size() -1]]);


        cout << "quantity: ";
        cin >> qtyOnHand[indexList[indexList.size() -1]];
        cout << "wholesale: ";
        cin >> wholeSale[indexList[indexList.size() -1]];

        cout << "retail: ";
        cin >> retail[indexList[indexList.size() -1]];


       cout << bookTitle[indexList[indexList.size() -1]] <<endl;
       cout << isbn[indexList[indexList.size() -1]]<<endl;
       cout << author[indexList[indexList.size() -1]]<<endl;
       cout << dateAdded[indexList[indexList.size() -1]]<<endl;
       cout << qtyOnHand[indexList[indexList.size() -1]]<<endl;
       cout << wholeSale[indexList[indexList.size() -1]]<<endl;
       cout << retail[indexList[indexList.size() -1]]<<endl;

            indexList.pop_back();

    }





    


    return;
            
}

void editBook(){

string userChoice;
int index  = -1;
            cout << '\n' << setw(15) << "You selected edit book\n\n";


         cout << '\n' << setw(15) << "Title of book: ";


        cin.ignore();
        getline(cin, userChoice);


    for(int i =0; i<MAX_STORAGE; i++){

        if(bookTitle[i] == userChoice){
            index = i;
        }

    }

    if(index == -1 ){
        cout << " No value";
        return;

    }else{

        bookInfo(bookTitle[index], isbn[index], author[index], publisher[index], dateAdded[index], qtyOnHand[index], wholeSale[index], retail[index]);


    }

    cout << "which you want to change:?";


}

void deleteBook(){
                cout << '\n' << setw(15) << "You selected delete  book\n\n";
    cout << "\n which you want tdelte\n";

    string userChoice;
    char user;
    

    int index = -1;

    cin.ignore();
            getline(cin, userChoice);


        for(int i =0; i<MAX_STORAGE; i++){

            if(bookTitle[i] == userChoice){
                index = i;
                
                bookInfo(bookTitle[index], isbn[index], author[index], publisher[index], dateAdded[index], qtyOnHand[index], wholeSale[index], retail[index]);
            }
        }

    cout << " Doy ou want book deetle? Y/N";

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



        cout << "GOODBYE";
        


    }

    return;

}