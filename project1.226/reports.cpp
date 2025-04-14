/******************************************************************
** Program: Serendipity Booksellers POS and inventory management software 
** Description: program will help employees sell and manage inventory


** Course: CS226 CRN 32842
** Professor: Huseyin Aygun
** Student: Thien Dinh
** Due Date: 04/13/2025
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


    
            bookFile.seekp(0L, ios::end);
            int totalRecords = bookFile.tellp()/ sizeof(invbook);




        cout << '\n';
        for(int bookIndex=0; bookIndex<totalRecords; bookIndex++){

            bookFile.clear();
            bookFile.seekg(sizeof(invbook) * bookIndex, ios::beg);
            if (!bookFile.eof()) {
                bookFile.read(reinterpret_cast<char *>(&invbook), sizeof(invbook));
            }


            if(invbook.Title[0] != '\0'){
                cout << left << "Title: "  <<  invbook.Title;
                cout << '\n' << "ISBN: " <<   invbook.ISBN<< '\n';
                cout <<         "Author: " << invbook.Author;
                cout <<'\n'  << "Date added: " << invbook.DateAdded<< '\n';
                cout <<         "Publisher: "  << invbook.Publisher; 
                cout <<'\n'  << "Quantity: " << invbook.QtyOnHand<< '\n'; 
                cout <<         "Wholesale value: " << invbook.WholesaleValue;
                cout <<'\n' <<  "Retail price: " << invbook.RetailValue << "\n\n"; 
            }
        }
        separateText();
        forcedUserWait();
}


void repWholesale(){
    double totalWholesaleValue{0.0};

        cout << '\n' << setw(40) << ' ' << "Book Wholesale Price report\n";
            displayDate();
            separateText();

               
            bookFile.seekp(0L, ios::end);
            int totalRecords = bookFile.tellp()/ sizeof(invbook);


        for(int i =0; i<totalRecords; i++){


            
            bookFile.clear();
            bookFile.seekg(sizeof(invbook) * i, ios::beg);
            if (!bookFile.eof()) {
                bookFile.read(reinterpret_cast<char *>(&invbook), sizeof(invbook));
            }

            if(invbook.Title[0] != '\0'){
            cout << left << "Title: "  <<  invbook.Title  << '\n';
            cout         << "ISBN: " <<  invbook.ISBN << endl;
            cout         << "Wholesale value: " << invbook.WholesaleValue << "\n\n";
            
            totalWholesaleValue += invbook.WholesaleValue * invbook.QtyOnHand;
     
            }
        }

        separateText();
            cout << '\n' << setw(55); 
            cout << "Wholesale value: " << totalWholesaleValue;
        forcedUserWait();
}







void repRetail(){
    double totalRetailValue{0.0};

    cout << '\n' << setw(40) << ' ' << "Book Retail Price report\n";
        displayDate();
        separateText();


               
        bookFile.seekp(0L, ios::end);
        int totalRecords = bookFile.tellp()/ sizeof(invbook);


        for(int i =0; i<totalRecords; i++){

            bookFile.clear();
            bookFile.seekg(sizeof(invbook) * i, ios::beg);
            if (!bookFile.eof()) {
                bookFile.read(reinterpret_cast<char *>(&invbook), sizeof(invbook));
            }
    

            if(invbook.Title[0] != '\0'){
            cout << left <<  "Title: "  <<  invbook.Title; 
            cout << '\n' <<  "ISBN: " <<   invbook.ISBN << endl;
            cout <<          "Retail price: " << invbook.RetailValue << "\n\n"; 

            totalRetailValue += invbook.RetailValue * invbook.QtyOnHand;
            }
        }
        separateText();
            cout << '\n' << setw(55); 
            cout << "Retail value: " << totalRetailValue;
        forcedUserWait();
}


void repQty(){

    int quantityIndexes[maximumStock];   

    cout << '\n' << setw(40) << ' ' << "Book Quantity report\n";
        displayDate();
        separateText();
        cout << '\n';

        quantitySort(quantityIndexes);



        int totalRecords = bookFile.tellp()/ sizeof(invbook);


            for (int i = 0; i < totalRecords; i++) {
                int bookIndex = quantityIndexes[i];
                
                if(invbook.Title[0] != '\0'){
                    cout << left <<  "Title: "  <<  invbook.Title; 
                    cout << '\n' <<  "ISBN: " <<   invbook.ISBN << endl;
                    cout <<          "Quantity: " << invbook.QtyOnHand << "\n\n"; 
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


        int totalRecords = bookFile.tellp()/ sizeof(invbook);


        for (int i = 0; i <totalRecords; i++) {
            int bookIndex = costIndexes[i];

            if(invbook.Title[0] != '\0'){
                cout << left <<  "Title: "  <<  invbook.Title; 
                cout << '\n' <<  "ISBN: " <<   invbook.ISBN << endl;
                cout <<          "Store price: " << invbook.WholesaleValue << "\n\n"; 
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

        int totalRecords = bookFile.tellp()/ sizeof(invbook);


        for (int i = 0; i < totalRecords; i++) {
            int bookIndex = ageIndexes[i];

            if(invbook.Title[0] != '\0'){
            cout << left <<  "Title: "  <<  invbook.Title << endl;
            cout << '\n' <<  "ISBN: " <<   invbook.ISBN << endl;
            cout <<          "Age: " << invbook.DateAdded << "\n\n"; 
                cout << '\n';
                }
        }
        separateText();
        forcedUserWait();
}




// https://www.w3schools.com/cpp/cpp_date.asp
// guide for displaying date







void quantitySort(int indices[]){

    const int SIZE = 20;

    BookData book;
    int maxIndex = 0;

    int totalRecords = bookFile.tellp()/ sizeof(invbook);

    for(int i =0; i<totalRecords; i++   )
        indices[i] = i;



    for (int i = 0; i < totalRecords; i++) {
        maxIndex = i;
        for (int j = i ; j < SIZE; j++) {
            

            //read into temporary book
            bookFile.clear();
            bookFile.seekg(sizeof(book) * j, ios::beg);
            if (!bookFile.eof()) {
                bookFile.read(reinterpret_cast<char *>(&book), sizeof(book));
            }


            //read into invbook
            bookFile.clear();
            bookFile.seekg(sizeof(invbook) * maxIndex, ios::beg);
            if (!bookFile.eof()) {
                bookFile.read(reinterpret_cast<char *>(&invbook), sizeof(invbook));
            }



            if (book.QtyOnHand > invbook.QtyOnHand) {
                maxIndex = j;
            }
        }
        int temp = indices[i];
        indices[i] = indices[maxIndex];
        indices[maxIndex] = temp;
    }

  }



  void costSort(int indices[]){


    /*
    const int SIZE = 20;


    BookData book;

    int totalRecords = bookFile.tellp()/ sizeof(invbook);

    for (int i = 0; i < totalRecords; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (invbook[indices[j]].WholesaleValue > invbook[indices[maxIndex]].WholesaleValue) {
                maxIndex = j;
            }
        }
        int temp = indices[i];
        indices[i] = indices[maxIndex];
        indices[maxIndex] = temp;
    }
*/
  }
  



  //definitely fix this at some point -> program doesnt accurately sort by date.
  void dateSort(int indices[]){
/*
   const int SIZE = 20;

    string dates[SIZE];


    int totalRecords = bookFile.tellp()/ sizeof(invbook);


    //setting up date array for date comparison
    for(int i =0; i<totalRecords; i++){
        dates[i] = invbook[i].DateAdded;
    }
//code from https://www.geeksforgeeks.org/removing-punctuations-given-string/
    // indexe
    for(int i=0; i<totalRecords; i++)
        indices[i] = i;
*/
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
    

  void displayDate(){
    time_t day;
    time(&day);
    cout << ctime(&day);
}





