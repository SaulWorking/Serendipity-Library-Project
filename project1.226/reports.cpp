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
#include "allheaders.h"
using namespace std;


const int maximumStock = 20;

void reports(){
    int reportsChoice;
    bool exitModule = false;

        while (exitModule == false) {
            cout << setw(20) << ' ' << "Serendipity Booksellers\n";
            cout << setw(25) << ' ' << "Reports\n\n";
            cout << setw(15) << ' ' << "1.	Inventory Listing\n";
            cout << setw(15) << ' ' << "2.\tInventory Wholesale Value\n";
            cout << setw(15) << ' ' << "3.	Inventory Retail Value\n";
            cout << setw(15) << ' ' << "4.	Listing by Quantity\n";
            cout << setw(15) << ' ' << "5.	Listing by Cost\n";
            cout << setw(15) << ' ' << "6.	Listing by Age\n";
            cout << setw(15) << ' ' << "7.	Return to Main Menu\n";
            cout << setw(15) << ' ' << "Enter Your Choice: ";
                cin >> reportsChoice;
                cin.ignore();
            switch (reportsChoice){
            case 1:
              repListing();
              break;
            case 2:
              repWholesale();
              break;
            case 3:
              repRetail();
              break;
            case 4:
              repQty();
              break;
            case 5:
              repCost();
              break;
            case 6:
              repAge();
              break;
            case 7:
              exitModule = true;
              break;
            default:
              cout << "\n\nEnter a number in the range 1-7" << endl;
              break;
            }
          }
    return;
}




void repListing(){
    cout << '\n' << setw(40) << ' ' << "Book Listing report\n";
    displayDate();
       separateText();

     cout << '\n';
        for(int bookIndex=0; bookIndex<maximumStock; bookIndex++){
            if(bookTitle[bookIndex][0] != '\0'){
                cout << left << "Title: "  <<  bookTitle[bookIndex];
                cout << '\n' << "ISBN: " <<   bookISBN[bookIndex] << '\n';
                cout <<         "Author: " << bookAuthor[bookIndex];
                cout <<'\n'  << "Date added: " << bookDateAdded[bookIndex] << '\n';
                cout <<         "Publisher: "  << bookPublisher[bookIndex]; 
                cout <<'\n'  << "Quantity: " << bookQtyOnHand[bookIndex] << '\n'; 
                cout <<         "Wholesale value: " << bookWholesaleValue[bookIndex];
                cout <<'\n' <<  "Retail price: " << bookRetailValue[bookIndex] << "\n\n"; 
            }
        }
        separateText();
        forcedUserWait();
}



void repWholesale(){
    double wholesaleValue{0.0};

        cout << '\n' << setw(40) << ' ' << "Book Wholesale Price report\n";
            displayDate();
            separateText();

        for(int i =0; i<maximumStock; i++){
            if(bookTitle[i][0] != '\0'){
            cout << left << "Title: "  <<  bookTitle[i]  << '\n';
            cout         << "ISBN: " <<   bookISBN[i] << endl;
            cout         << "Wholesale value: " << bookWholesaleValue[i] << "\n\n";
            
            wholesaleValue += bookWholesaleValue[i] * bookQtyOnHand[i];
            }
        }

        separateText();
            cout << '\n' << setw(55); 
            cout << "Wholesale value: " << wholesaleValue;
        forcedUserWait();
}







void repRetail(){
    double retailValue{0.0};

    cout << '\n' << setw(40) << ' ' << "Book Retail Price report\n";
    displayDate();
            separateText();

        for(int i =0; i<maximumStock; i++){
            if(bookTitle[i][0] != '\0'){
            cout << left <<  "Title: "  <<  bookTitle[i]; 
            cout << '\n' <<  "ISBN: " <<   bookISBN[i] << endl;
            cout <<          "Retail price: " << bookRetailValue[i] << "\n\n"; 

            retailValue += bookRetailValue[i] * bookQtyOnHand[i];
            }
        }
        separateText();
            cout << '\n' << setw(55); 
            cout << "Retail value: " << retailValue;
        forcedUserWait();
}


void repQty(){

    int quantityIndexes[maximumStock];   


    cout << '\n' << setw(40) << ' ' << "Book Quantity report\n";
        displayDate();
        separateText();
        cout << '\n';

        quantitySort(quantityIndexes);

            for (int i = 0; i < maximumStock; i++) {
                int bookIndex = quantityIndexes[i];
                if(bookTitle[i][0] != '\0'){
                    cout << left << "Title: "  <<  bookTitle[bookIndex];
                    cout << '\n' << "ISBN: " <<   bookISBN[bookIndex] << endl;
                    cout <<         "Quantity: " << bookQtyOnHand[bookIndex] << endl;
                    cout << '\n';
                    }
            }       
        separateText();
        forcedUserWait();
}
void repCost(){

    int costIndexes[maximumStock];   


    cout << '\n' << setw(40) << ' ' << "Book Cost report\n";
        displayDate();
        separateText();
        costSort(costIndexes);

        for (int i = 0; i < 10; i++) {
            int bookIndex = costIndexes[i];

            if(bookTitle[i][0] != '\0'){
                cout << left << "Title: "  <<  bookTitle[bookIndex];
                cout << '\n' << "ISBN: " <<   bookISBN[bookIndex] << endl;
                cout <<         "wholesale cost: " << bookWholesaleValue[bookIndex] << endl;
                cout << '\n';
                }
        }
        separateText();
        forcedUserWait();
}
void repAge(){

    int ageIndexes[maximumStock];  

    cout << '\n' << setw(40) << ' ' << "Book Age report\n";
        displayDate();
        separateText();
        dateSort(ageIndexes);

        for (int i = 0; i < 10; i++) {
            int bookIndex = ageIndexes[i];

            if(bookTitle[i][0] != '\0'){
                cout << left << "Title: "  <<  bookTitle[bookIndex];
                cout << '\n' << "ISBN: " <<   bookISBN[bookIndex] << endl;
                cout <<         "Date Added: " << bookDateAdded[bookIndex] << endl;
                cout << '\n';
                }
        }
        separateText();
        forcedUserWait();
}



/*  guide for displaying c++ date

https://www.w3schools.com/cpp/cpp_date.asp
    
    */

void displayDate(){
    time_t day;
    time(&day);
    cout << ctime(&day);
}




void quantitySort(int indices[]){

    const int SIZE = 10;

    for(int i=0; i<SIZE; i++)
        indices[i] = i;

    for (int i = 0; i < SIZE - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (bookQtyOnHand[indices[j]] > bookQtyOnHand[indices[maxIndex]]) {
                maxIndex = j;
            }
        }
        int temp = indices[i];
        indices[i] = indices[maxIndex];
        indices[maxIndex] = temp;
    }

  }



  void costSort(int indices[]){

    const int SIZE = 10;

    for(int i=0; i<SIZE; i++)
        indices[i] = i;

    for (int i = 0; i < SIZE - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (bookWholesaleValue[indices[j]] > bookWholesaleValue[indices[maxIndex]]) {
                maxIndex = j;
            }
        }
        int temp = indices[i];
        indices[i] = indices[maxIndex];
        indices[maxIndex] = temp;
    }

  }
  



  //definitely fix this at some point -> program doesnt accurately sort by date.
  void dateSort(int indices[]){

    const int SIZE = 10;


    string dates[SIZE];

    for(int i =0; i<SIZE; i++){
        dates[i] = bookDateAdded[i];
    }

//code from https://www.geeksforgeeks.org/removing-punctuations-given-string/


    for(int index =0; index<SIZE; index++){

        for (int i = 0, len = dates[index].size(); i < len; i++)
        {
            // check whether parsing character is punctuation or not
            if (ispunct(dates[index][i]))
            {
                dates[index].erase(i--, 1);
                len = dates[index].size();
            }
        }

    }  

    // indexes
    for(int i=0; i<SIZE; i++)
        indices[i] = i;

    

    

    for (int i = 0; i < SIZE - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (bookDateAdded[indices[j]] > bookDateAdded[indices[maxIndex]]) {
                maxIndex = j;
            }
        }


        int temp = indices[i];
        indices[i] = indices[maxIndex];
        indices[maxIndex] = temp;
    }


  }



  void separateText(){

    for(int i =0; i< 100; i++){
        cout << '-';
    }
    cout << '\n';

  }



  void forcedUserWait(){
    string userInput;

    cout << '\n';
    cout << "\nPress enter to continue.";
    getline(cin, userInput);
    cout << "\n\n\n";

  }
    





