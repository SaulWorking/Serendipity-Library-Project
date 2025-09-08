/******************************************************************
** Program: Serendipity Booksellers POS and inventory management software 
** Description: program will help employees sell and manage inventory


** Course: CS226 CRN 32842
** Professor: Huseyin Aygun
** Student: Thien Dinh
** Due Date: 04/27/2025
******************************************************************/

#include <iostream>
#include <iomanip>
#include "../include/headers.h"

const int maximumStock = 20;

void reports(){
    int reportsChoice{0};
    bool exitModule = false;

    while (exitModule == false) {
        menuHelper.menuOutput("Report");

        cin >> reportsChoice;
            menuHelper.separateText();
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
            cout << "\n\nEnter a number in the range 1-7" <<  endl;
                break;
            }
        }
    return;
}

void repListing(){
    cout << '\n' << setw(40) << ' ' << "Book Listing report\n";

    menuHelper.displayDate();
    menuHelper.separateText();
    cout << '\n';
        for(int bookIndex=0; bookIndex<bookFile.storageSize(); bookIndex++){
             bookFile.bookRead(invbook, bookIndex);
            if(!invbook.isEmpty()){
                
                cout << "\t[Book " << bookIndex + 1  << ']' <<  endl;
                invbook.bookIndexInformation();
            }
        }
        menuHelper.separateText();
        menuHelper.forcedUserWait();
}


void repWholesale(){
    double totalWholesaleValue{0.0};

    cout << '\n' << setw(40) << ' ' << "Book Wholesale Price report\n";
        menuHelper.displayDate();
        menuHelper.separateText();

        for(int bookIndex=0; bookIndex<bookFile.storageSize(); bookIndex++){
             bookFile.bookRead(invbook, bookIndex);
            
             if(!invbook.isEmpty()){
                cout << "[Book " << bookIndex + 1  << ']' <<  endl;
                invbook.printReport("Wholesale");
                totalWholesaleValue += invbook.getWholesale() * invbook.getQty(); 
            }
        }
        menuHelper.separateText();
            cout << '\n' << setw(55); 
            cout << "Wholesale value: " << totalWholesaleValue;
        menuHelper.forcedUserWait();
}




void repRetail(){
    double totalRetailValue{0.0};

    cout << '\n' << setw(40) << ' ' << "Book Retail Price report\n";
    menuHelper.displayDate();
    menuHelper.separateText();
        
        for(int bookIndex=0; bookIndex<bookFile.storageSize(); bookIndex++){
             bookFile.bookRead(invbook, bookIndex);
            if(!invbook.isEmpty()){
                cout << "[Book " << bookIndex + 1  << ']' <<  endl;
                invbook.printReport("Retail");
                totalRetailValue += invbook.getRetail() * invbook.getQty();
            }

        }
        menuHelper.separateText();
        cout << '\n' << setw(55); 
        cout << "Retail value: " << totalRetailValue;
        menuHelper.forcedUserWait();
}


/// brief 
void repQty(){
    int quantityIndexes[maximumStock];   
    cout << '\n' << setw(40) << ' ' << "Book Quantity report\n";
    menuHelper.displayDate();
    menuHelper.separateText();

        quantitySort(quantityIndexes);
            for (int i = 0; i < bookFile.storageSize(); i++) {
                int bookIndex = quantityIndexes[i];

                //print according to byte size

                 bookFile.bookRead(invbook, bookIndex);

                if(!invbook.isEmpty()){

                    cout << "[Book " << bookIndex + 1  << ']' <<  endl;
                    invbook.printReport("Quantity");
                }
            }       
        menuHelper.separateText();
        menuHelper.forcedUserWait();
}
void repCost(){

    int costIndexes[maximumStock];   

    cout << '\n' << setw(40) << ' ' << "Book Cost report\n";
        menuHelper.displayDate();
        menuHelper.separateText();
        costSort(costIndexes);

        for (int i = 0; i <bookFile.storageSize(); i++) {
            int bookIndex = costIndexes[i];
             bookFile.bookRead(invbook, bookIndex);

            if(!invbook.isEmpty()){
                cout << "[Book " << bookIndex + 1  << ']' <<  endl;
                invbook.printReport("Retail");
            }
        }
        menuHelper.separateText();
        menuHelper.forcedUserWait();
}
void repAge(){
    int ageIndexes[maximumStock];  

    cout << '\n' << setw(40) << ' ' << "Book Age report\n";
    menuHelper.displayDate();
    menuHelper.separateText();

        dateSort(ageIndexes);
        for (int i = 0; i < bookFile.storageSize(); i++) {
            int bookIndex = ageIndexes[i];

             bookFile.bookRead(invbook, bookIndex);

                if(!invbook.isEmpty()){
                    cout << "[Book " << bookIndex + 1  << ']' <<  endl;

                    invbook.printReport("DateAdded");

                }
        }
        menuHelper.separateText();
        menuHelper.forcedUserWait();
}

// https://www.w3schools.com/cpp/cpp_date.asp
// guide for displaying date
void quantitySort(int indices[]){

    InventoryBook book;
    int maxIndex = 0;

    //set up indexes 
    for(int i =0; i<bookFile.storageSize(); i++)
        indices[i] = i;

    //start 
    for (int i = 0; i < bookFile.storageSize() - 1; i++) {
        maxIndex = i;
    
        for (int j = i + 1; j < bookFile.storageSize(); j++) {
            // read invbook (current max)

             bookFile.bookRead(invbook, indices[maxIndex]);
             bookFile.bookRead(book, indices[j]);
            // read book (candidate)
            // compare retail values
            if (book.getQty() > invbook.getQty()) {
                maxIndex = j;
            }
        }
    if(maxIndex != i){
        swap(indices[i], indices[maxIndex]);
    }
        cout <<  endl;
    }   
}
void costSort(int indices[]){
    InventoryBook book;
    int maxIndex = 0;

    for(int i =0; i<bookFile.storageSize(); i++){
        indices[i] = i;
    }
        for (int i = 0; i < bookFile.storageSize() - 1; i++) {
            maxIndex = i;
        
            for (int j = i + 1; j < bookFile.storageSize(); j++) {
                // read invbook (current max)

                 bookFile.bookRead(invbook, indices[maxIndex]);
                 bookFile.bookRead(book, indices[j]);

            
                // compare retail values
                if (book.getRetail() > invbook.getRetail()) {
                    maxIndex = j;
                }
            }

        if(maxIndex != i){
            swap(indices[i], indices[maxIndex]);
        }
        cout <<  endl;
    }
    
  }
  

  //definitely fix this at some point -> program doesnt accurately sort by date.
void dateSort(int indices[]){

   InventoryBook book;
   int maxindex = 0;

   for(int i =0; i<bookFile.storageSize(); i++){
        indices[i] = i;
    }
        for (int i = 0; i < bookFile.storageSize()-1; i++) {
            maxindex = i;
    
            //read max value
            for (int j = i+1 ; j < bookFile.storageSize(); j++) {
                //read into invbook
                 bookFile.bookRead(invbook, indices[maxindex]);
                 bookFile.bookRead(book, indices[j]);

                if (book.getDateAdded() < invbook.getDateAdded()) {
                    maxindex = j;
                }
            }
            //swap
            swap(indices[i], indices[maxindex]);
            cout <<  endl;
        }
} 





7

//report swap


void BookData::printReport(string reportType){
    if(reportType == "Wholesale"){
        cout << left << "Title: "  <<  invbook.getTitle()  << '\n';
        cout         << "ISBN: " <<  invbook.getISBN() <<  endl;
        cout         << "Wholesale value: " << invbook.getWholesale() << "\n\n";

    }
    if(reportType == "Retail"){
        cout << left << "Title: "  <<  invbook.getTitle()  << '\n';
        cout         << "ISBN: " <<  invbook.getISBN() <<  endl;
        cout         << "Retail Value: " << invbook.getRetail() << "\n\n";
    }
    if(reportType == "Quantity"){
        cout << left << "Title: "  <<  invbook.getTitle()  << '\n';
        cout         << "ISBN: " <<  invbook.getISBN() <<  endl;
        cout         << "Quantity: " << invbook.getQty() << "\n\n";
        
    }   
    if(reportType == "DateAdded"){
        cout << left << "Title: "  <<  invbook.getTitle()  << '\n';
        cout         << "ISBN: " <<  invbook.getISBN() <<  endl;
        cout         << "Date: " << invbook.getDateAdded() << "\n\n";
     
    }
}


