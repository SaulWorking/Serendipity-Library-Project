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

        bookFile.clear();
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

            bookFile.clear();
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
        
        bookFile.clear();
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
                cout         << "Retail value: " << invbook.getRetail() << "\n\n";
                
                totalRetailValue += invbook.getRetail() * invbook.getQty();
         
            }
        }
        separateText();
            cout << '\n' << setw(55); 
            cout << "Retail value: " << totalRetailValue;
        forcedUserWait();
}


/// brief 
void repQty(){



    
    int quantityIndexes[maximumStock];   

    cout << '\n' << setw(40) << ' ' << "Book Quantity report\n";
        displayDate();
        separateText();
        cout << '\n';

        quantitySort(quantityIndexes);

        bookFile.clear();
        bookFile.seekp(0L, ios::end);
        int totalRecords = bookFile.tellp()/ sizeof(invbook);

        for(int i =0; i < totalRecords; i++){
            cout << quantityIndexes[i] <<  ' ';
        }

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
                    cout         << "Quantity: " << invbook.getQty() << "\n\n";
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

        bookFile.clear();
        bookFile.seekp(0L, ios::end);
        int totalRecords = bookFile.tellp()/ sizeof(invbook);



        for(int i =0; i < totalRecords; i++){
            cout << costIndexes[i] <<  ' ';
        }

        for (int i = 0; i <totalRecords; i++) {
            int bookIndex = costIndexes[i];


            bookFile.clear();
            bookFile.seekg(sizeof(invbook) * bookIndex, ios::beg);
            if (!bookFile.eof()) {
                bookFile.read(reinterpret_cast<char *>(&invbook), sizeof(invbook));
            }


            if(invbook.getTitle()[0] != '\0'){
                cout << left << "Title: "  <<  invbook.getTitle()  << '\n';
                cout         << "ISBN: " <<  invbook.getISBN() << endl;
                cout         << "Retail Value: " << invbook.getRetail() << "\n\n";
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


        bookFile.clear();
        bookFile.seekp(0L, ios::end);
        int totalRecords = bookFile.tellp()/ sizeof(invbook);


        for (int i = 0; i < totalRecords; i++) {
            int bookIndex = ageIndexes[i];

            bookFile.clear();
            bookFile.seekg(sizeof(invbook) * bookIndex, ios::beg);
            if (!bookFile.eof()) {
                bookFile.read(reinterpret_cast<char *>(&invbook), sizeof(invbook));
            }

                if(invbook.getTitle()[0] != '\0'){
                    cout << left << "Title: "  <<  invbook.getTitle()  << '\n';
                    cout         << "ISBN: " <<  invbook.getISBN() << endl;
                    cout         << "Date: " << invbook.getDateAdded() << "\n\n";
                }
        }
        separateText();
        forcedUserWait();
}




// https://www.w3schools.com/cpp/cpp_date.asp
// guide for displaying date







void quantitySort(int indices[]){

    BookData book;
    int maxIndex = 0;

    bookFile.clear();
    bookFile.seekp(0L, ios::end);
    int totalRecords = bookFile.tellp()/ sizeof(invbook);

    //set up indexes  :3
    for(int i =0; i<totalRecords; i++)
        indices[i] = i;


    //start 
    for (int i = 0; i < totalRecords - 1; i++) {
        maxIndex = i;
    
        for (int j = i + 1; j < totalRecords; j++) {
            // read invbook (current max)
            bookFile.clear();
            bookFile.seekg(sizeof(invbook) * indices[maxIndex], ios::beg);
            if (!bookFile.eof()) {
                bookFile.read(reinterpret_cast<char *>(&invbook), sizeof(invbook));
            }

            // read book (candidate)
            bookFile.clear();
            bookFile.seekg(sizeof(book) * indices[j], ios::beg);
            if (!bookFile.eof()) {
                bookFile.read(reinterpret_cast<char *>(&book), sizeof(book));
            }

            // compare retail values
            if (book.getQty() > invbook.getQty()) {
                maxIndex = j;
            }

        }

        
    if(maxIndex != i)
        swap(indices[i], indices[maxIndex]);

    cout << endl;

    }   
        
 
}




  void costSort(int indices[]){


    BookData book;
    int maxIndex = 0;

    bookFile.clear();
    bookFile.seekp(0L, ios::end);
    int totalRecords = bookFile.tellp()/ sizeof(invbook);

    for(int i =0; i<totalRecords; i++)
        indices[i] = i;



        for (int i = 0; i < totalRecords - 1; i++) {
            maxIndex = i;
        
            for (int j = i + 1; j < totalRecords; j++) {
                // read invbook (current max)
                bookFile.clear();
                bookFile.seekg(sizeof(invbook) * indices[maxIndex], ios::beg);
                bookFile.read(reinterpret_cast<char *>(&invbook), sizeof(invbook));
        
                // read book (candidate)
                bookFile.clear();
                bookFile.seekg(sizeof(book) * indices[j], ios::beg);
                bookFile.read(reinterpret_cast<char *>(&book), sizeof(book));
        
                // compare retail values
                if (book.getRetail() > invbook.getRetail()) {
                    maxIndex = j;
                }
            }

            
        if(maxIndex != i)
            swap(indices[i], indices[maxIndex]);

        cout << endl;
    }
    
  }
  







  //definitely fix this at some point -> program doesnt accurately sort by date.
  void dateSort(int indices[]){

   const int SIZE = 20;

   BookData book;
   int mindex = 0;

   bookFile.clear();
   bookFile.seekp(0L, ios::end);
   int totalRecords = bookFile.tellp()/ sizeof(invbook);

   
   for(int i =0; i<totalRecords; i++)
        indices[i] = i;

    
        for (int i = 0; i < totalRecords-1; i++) {
            mindex = i;
    
            //read max value
            for (int j = i+1 ; j < totalRecords; j++) {
                //read into invbook
                bookFile.clear();
                bookFile.seekg(sizeof(invbook) * indices[mindex], ios::beg);
                if (!bookFile.eof()) {
                    bookFile.read(reinterpret_cast<char *>(&invbook), sizeof(invbook));
                }
                //read into tempbook
                bookFile.clear();
                bookFile.seekg(sizeof(book) * indices[j], ios::beg);
                if (!bookFile.eof()) {
                    bookFile.read(reinterpret_cast<char *>(&book), sizeof(book));
                }
                if (book.getDateAdded() < invbook.getDateAdded()) {
                    mindex = j;
                }
            }
            //swap



            swap(indices[i], indices[mindex]);

    
        for(int i =0; i < totalRecords; i++){
            cout << indices[i] <<  ' ';
        }
            cout << endl;
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
    

  void displayDate(){
    time_t day;
    time(&day);
    cout << ctime(&day);
}



void swap(int &num1, int &num2){

    int temp = num1;

    //num1 becomes num2
    num1 = num2;
    //num2 becomes num1
    num2 = temp;
    

}
void swap(double &num1, double &num2){


    double temp = num1;

    //num1 becomes num2
    num1 = num2;
    //num2 becomes num1
    num2 = temp;
    
}


