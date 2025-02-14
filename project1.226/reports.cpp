#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void listInventory();
void listWholesaleValue();
void listRetailValue();
void reportInfo(){

int userChoice;
double userPay;



cout << setw(20) << " " << "Serendipity Booksellers\n";
cout << setw(25) << " " << "Reports\n";
cout << setw(15) << " " << "1.	Inventory Listing\n";
cout << setw(15) << " " << "2.	Inventory Wholesale Value\n";
cout << setw(15) << " " <<" 3.	Inventory Retail Value\n";
cout << setw(15) << " " <<" 4.	Listing by Quantity\n";
cout << setw(15) << " " <<" 5.	Listing by Cost\n";
cout << setw(15) << " " <<" 6.	Listing by Age\n";
cout << setw(15) << " " <<" 7.	Return to Main Menu\n";

cout << setw(15) << " " << "Enter Your Choice: ";

while(userChoice < 1 || userChoice >7){

    cin >> userChoice;
    
    if(userChoice < 1 || userChoice >7){
    cout << '\n' << setw(15) << "Please enter a number in the range 1 - 7.\n\n";
    
    reportInfo();

    }
}



switch(userChoice){

    case 1:

    cout << '\n' << setw(15) << "you have item 1\n";

        break;
    case 2:

    cout << '\n' << setw(15) << "you have item 2\n";

        break;
    case 3:

    cout << '\n' << setw(15) << "you have item 3\n";

        break;
    case 4:
    cout << '\n' << setw(15) << "you have item 4\n";

        break;
    case 5:
    cout << '\n' << setw(15) << "you have item 5\n";

        break;
    case 6:
    cout << '\n' << setw(15) << "you have item 6\n";

        break;
    case 7:
    cout << '\n' << setw(15) << "you have item 7\n";
    
    

break;

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