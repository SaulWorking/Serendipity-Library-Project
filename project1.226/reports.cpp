#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "reports.h"


using namespace std;





void reports(){


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

cout << "\n\n";

     while(userChoice <1 || userChoice >7){

            cout << "\n" << setw(15) << " " << "Please enter a valid number 1-7.\n";

            cin >> userChoice;
        }

        reportsCheck(userChoice);

 
    return;
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

        cout << '\n' << setw(15) << "you selected Inventory Listing\n";


}
void repWholesale(){
        cout << '\n' << setw(15) << "you selected Inventory Wholesale value\n";

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





//functions for later stages of the project


/*
void listInventory(){
ifstream readFile;
readFile.open("report.txt");
string reportWord = "";
int lineCounter = 1;

while(getline(readFile, reportWord)){
    if(lineCounter >= 2){
        cout << "\n\n";
        lineCounter = 1;
    }
    cout << reportWord;

    lineCounter++;

}

readFile.close();
    return;
}

void listWholesaleValue(){

ifstream readFile;
readFile.open("report.txt");
string reportWord = "";

double totalWholesaleValue = 0.0;
int lineCounter = 0;
int wordCounter = 1;


while(getline(readFile, reportWord, ',')){


    if(wordCounter==7){

    if(lineCounter >=1){
  cout << "Book " << lineCounter << " cost: " << reportWord << endl;

    totalWholesaleValue += stod(reportWord);

    }    
        wordCounter = 0;

        lineCounter++;
    }
    

    wordCounter++;
}

cout << "Your wholesale value total is: $" << totalWholesaleValue << endl;

readFile.close();

    return;
}

void listRetailValue(){
ifstream readFile;
readFile.open("report.txt");
string reportWord = "";

double totalRetailValue = 0.0;
int lineCounter = 0;
int wordCounter = 1;
char ignoreChar = ',';

while(getline(readFile, reportWord, ignoreChar)){

        ignoreChar = ',';

    if(wordCounter==8){
        cout << reportWord << endl;
    }

  cout << reportWord << " ";

        wordCounter++;


}   



cout << "Your retail value total is: $" << totalRetailValue << endl;

readFile.close();



    
}

*/


