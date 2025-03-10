#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "reports.h"
#include "inventory.h"
using namespace std;


int reports(){

    int userChoice;

    cout << setw(20) << " " << "Serendipity Booksellers\n";
    cout << setw(25) << " " << "Reports\n\n";
    cout << setw(15) << " " << "1.	Inventory Listing\n";
    cout << setw(15) << " " << "2.	Inventory Wholesale Value\n";
    cout << setw(15) << " " <<" 3.	Inventory Retail Value\n";
    cout << setw(15) << " " <<" 4.	Listing by Quantity\n";
    cout << setw(15) << " " <<" 5.	Listing by Cost\n";
    cout << setw(15) << " " <<" 6.	Listing by Age\n";
    cout << setw(15) << " " <<" 7.	Return to Main Menu\n";
    cout << setw(15) << " " << "Enter Your Choice: ";

        cin >> userChoice;

        cout << '\n';

        while(userChoice <1 || userChoice >7){

                cout << "\n" << setw(15) << ' ' << "Please enter a valid number 1-7.\n";

                cin >> userChoice;
            }
            reportsCheck(userChoice);

    return userChoice;
}










void reportsCheck(int userInput){

    switch(userInput){

        case 1:
     repListing();        
     reports();
            break;
        case 2:
    repWholesale();
    reports();
            break;
        case 3:
    repRetail();
    reports();
            break;
        case 4:
    repQty();
    reports();
            break;

         case 5:   
    repCost();
    reports();
            break;
        case 6:
    repAge();
    reports();
            break;
        case 7:
           
        break;


    }

}



void repListing(){

    string wait;
       


       cout << '\n' << setw(55) << "Inventory Report\n"; 
        cout << '\n' << setw(55); 
        displayDate();

        for(int i =0; i< 100;i++){
            cout << '-';
        }

        cout << '\n';

        for(int i =0; i<20; i++){

            if(bookTitle[i] != ""){
            cout << left << "Title: "  <<  bookTitle[i]  << '\n' << "ISBN: " <<   isbn[i] << '|' << "Author: " << author[i] << '|';
            cout << "Publisher: "  << publisher[i]  << '|' << "Wholesale value: " << wholeSale[i] << '|' << "Retail price: " <<retail[i] << '|'<<  "\n\n";
            }

        }
        
        for(int i =0; i< 100;i++){
            cout << '-';
        }


        cout << '\n';
        cout << "\nPress enter to continue.";
        cin.ignore();
        getline(cin, wait);
        cout << '\n';
}
void repWholesale(){



string wait;
double WholesaleValue{0.0};


       cout << '\n' << setw(55) << "Wholesale report\n";
        cout << '\n' << setw(55); 
        displayDate();

        for(int i =0; i< 100;i++){
            cout << '-';
        }

        cout << '\n';

        for(int i =0; i<20; i++){

            if(bookTitle[i] != ""){
            cout << left << "Title: "  <<  bookTitle[i]  << '\n' << "ISBN: " <<   isbn[i] << '|' << "Author: " << author[i] << '|' << "Date added: " << dateAdded << '|';
            cout << "Publisher: "  << publisher[i]  << '|' << "Quantity: " << qtyOnHand[i] << '|' << "Wholesale value: " << wholeSale[i] << '|' << "Retail price: " <<retail[i] << '|'; 
            
            WholesaleValue += wholeSale[i];
            cout << WholesaleValue << endl;
            
            }
        }
        
        for(int i =0; i< 100;i++){
            cout << '-';
        }

        cout << '\n' << setw(55); 
        cout << "Wholesale value: " << WholesaleValue;
        cout << WholesaleValue;
        cout << '\n';
        cout << "\nPress enter to continue.";
        cin.ignore();
        getline(cin, wait);
        cout << '\n';
}

void repRetail(){
        cout << '\n' << setw(15) << "you selected Inventory retail value\n";

}
void repQty(){
        cout << '\n' << setw(15) << "you selected Listing by quantity\n";

}
void repCost(){
        cout << '\n' << setw(15) << "you selected  Listing by cost\n";

}
void repAge(){
        cout << '\n' << setw(15) << "you selected Listing by age\n";

}



/*  guide for displaying c++ date

https://www.w3schools.com/cpp/cpp_date.asp
    
    */

void displayDate(){

    time_t day;

    time(&day);

    cout << ctime(&day);


}