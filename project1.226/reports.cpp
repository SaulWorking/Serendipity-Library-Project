#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void listInventory();
void listWholesaleValue();
void listRetailValue();

void reportInfo(){




cout << "Serendipity Booksellers Reports\n";
cout << " 1.	Inventory Listing\n";
cout << " 2.	Inventory Wholesale Value\n";
cout << " 3.	Inventory Retail Value\n";
cout << " 4.	Listing by Quantity\n";
cout << " 5.	Listing by Cost\n";
cout << " 6.	Listing by Age\n";
cout <<" 7.	Return to Main Menu\n";

cout << "Enter Your Choice:\n";

int userChoice;
double userPay;
cin >> userChoice;
cin.ignore();
switch(userChoice){

    case 1:
listInventory();

        break;
    case 2:

listWholesaleValue();

        break;
    case 3:

// listRetailValue();
        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    case 7:

        break;
    default:

    cout << "Restart. "<<endl;

}









    return;
}

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



cout << "Your retial value total is: $" << totalRetailValue << endl;

readFile.close();



    
}