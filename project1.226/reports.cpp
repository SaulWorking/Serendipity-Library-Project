/******************************************************************
** Program: Serendipity Booksellers POS and inventory management software 
** Description: program will help employees sell and manage inventory


** Course: CS226 CRN 32842
** Professor: Huseyin Aygun
** Student: Thien Dinh
** Due Date: 04/20/2025
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

        if(invbook.getTitle()[0] != '\0'){
            cout << left << "Title: "  <<  invbook.getTitle();
            cout << '\n' << "ISBN: " <<   invbook.getISBN()<< '\n';
            cout <<         "Author: " << invbook.getAuthor();
            cout <<'\n'  << "Date added: " << invbook.getDateAdded()<< '\n';
            cout <<         "Publisher: "  << invbook.getPub(); 
            cout <<'\n'  << "Quantity: " << invbook.getQty()<< '\n'; 
            cout <<         "Wholesale value: " << invbook.getWholesale();
            cout <<'\n' <<  "Retail price: " << invbook.getRetail() << "\n\n"; 
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

            if(invbook.getTitle()[0] != '\0'){
            cout << left << "Title: "  <<  invbook.getTitle()  << '\n';
            cout         << "ISBN: " <<  invbook.getISBN() << endl;
            cout         << "Wholesale value: " << invbook.getWholesale() << "\n\n";
            
            totalWholesaleValue += invbook.getWholesale() * invbook.getQty();
     
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
    

            if(invbook.getTitle()[0] != '\0'){
                cout << left << "Title: "  <<  invbook.getTitle()  << '\n';
                cout         << "ISBN: " <<  invbook.getISBN() << endl;
                cout         << "Wholesale value: " << invbook.getWholesale() << "\n\n";
                
                totalRetailValue += invbook.getRetail() * invbook.getQty();
         
            }
        }
        separateText();
            cout << '\n' << setw(55); 
            cout << "Retail value: " << totalRetailValue;
        forcedUserWait();
}


/// @brief 
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

                //print according to byte size

                bookFile.clear();
                bookFile.seekg(sizeof(invbook) * bookIndex, ios::beg);
                if (!bookFile.eof()) {
                    bookFile.read(reinterpret_cast<char *>(&invbook), sizeof(invbook));
                }
    


                if(invbook.getTitle()[0] != '\0'){




                    cout << left << "Title: "  <<  invbook.getTitle()  << '\n';
                    cout         << "ISBN: " <<  invbook.getISBN() << endl;
                    cout         << "Wholesale value: " << invbook.getWholesale() << "\n\n";
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

            if(invbook.getTitle()[0] != '\0'){
                cout << left << "Title: "  <<  invbook.getTitle()  << '\n';
                cout         << "ISBN: " <<  invbook.getISBN() << endl;
                cout         << "Wholesale value: " << invbook.getWholesale() << "\n\n";
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

                if(invbook.getTitle()[0] != '\0'){
                    cout << left << "Title: "  <<  invbook.getTitle()  << '\n';
                    cout         << "ISBN: " <<  invbook.getISBN() << endl;
                    cout         << "Wholesale value: " << invbook.getWholesale() << "\n\n";
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


    //bytes for storage
    for(int i =0; i<totalRecords; i++   )
        indices[i] = i;






    for (int i = 0; i < totalRecords -1; i++) {
        maxIndex = i;

        //read max value
        bookFile.clear();
        bookFile.seekg(sizeof(book) * i, ios::beg);
        if (!bookFile.eof()) {
            bookFile.read(reinterpret_cast<char *>(&book), sizeof(book));
        }


        for (int j = i+1 ; j < totalRecords; j++) {
            




            //read into invbook
            bookFile.clear();
            bookFile.seekg(sizeof(invbook) * j, ios::beg);
            if (!bookFile.eof()) {
                bookFile.read(reinterpret_cast<char *>(&invbook), sizeof(invbook));
            }


            if (book.getQty() < invbook.getQty()) {
                maxIndex = j;
            }
        }
        //swap
        int temp = indices[i];
        //index becomes max index
        indices[i] = indices[maxIndex];
        //max index becomes temp;
        //swap
        indices[maxIndex] = temp;

        for(int i =0; i < totalRecords; i++){

            cout << indices[maxIndex] <<  ' ';
        
        }
        cout << endl;
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





