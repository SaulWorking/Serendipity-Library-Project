#ifndef general_header
#define general_header

#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;
//general purpose functions/variables
    //print error message
    void printError();
    //prints '-' 100 times
    void separateText();
    //asks for user to press enter
    void forcedUserWait();
    //takes book index and displays bookinfo
    void bookIndexInformation(int);
//bookinfo header 
    //regurgitates book information 
    void bookInfo(char[], char[], char[], char[], char[], int, double, double);
//cashier header
    //prompts user to purchase book
    void cashier();
    //finds index of book ISBN
    int ISBNLookup(string);
//inventory header
    //sorting quantity
    void quantitySort(int []);
    //sorting cost
    void costSort(int []);
    //sorting date
    void dateSort(int[]);
    //displaye date
    void displayDate();
    //convert entire c-string to uppercase
    void strUpper(char *word);
//connect inventory to entire program

class BookData{
    //Inventory book member variables/members
    private:
        char bookTitle[51];
        char bookISBN[14];    
        char bookAuthor[31];
        char bookPublisher[31];
        char bookDateAdded[11]; 

        int bookQtyOnHand;     
        double bookWholesaleValue;
        double bookRetailValue;
    public:
        //set functions for data
        void setTitle(char * title)
            {strncpy(bookTitle, title, 51);}  
        void setISBN(char *ISBN)
            {strncpy(bookISBN, ISBN, 14);}
        void setAuthor(char *author)
            {strncpy(bookAuthor, author, 31);}	 
        void setPub(char *publisher)
            {strncpy(bookPublisher, publisher, 31);}	
        void setDateAdded(char *date)
            {strncpy(bookDateAdded, date, 11);}
        void setQty(int quantity) 
            {bookQtyOnHand = quantity;}
        void setWholesale(double wholesale)
            {bookWholesaleValue = wholesale;}	 
        void setRetail(double retail)
            {bookRetailValue = retail;}
        void removeBook()
        {
            //remember to write this change in file
            bookTitle[0] = '\0';
            bookISBN[0] = '\0';
            bookAuthor[0]= '\0';
            bookPublisher[0] = '\0';
            bookDateAdded[0]= '\0';
            bookQtyOnHand = 0;
            bookRetailValue = 0.0;
            bookWholesaleValue = 0.0;
        }
        int isEmpty(){
            //checks for first character of Title at specified book index
            if(bookTitle[0] == '\0'){
                return true;
            }else{
                return false;
            }
        }

        //get functions
        //char * is c-string
        char * getTitle()
            {return bookTitle;}
        char * getISBN()
            {return bookISBN;}
        char * getAuthor()
            {return bookAuthor;}
        char * getPub()
            {return bookPublisher;}
        char * getDateAdded()
            {return bookDateAdded;}
        int getQty()
            {return bookQtyOnHand;}
        double getWholesale()
            {return bookWholesaleValue;}
        double getRetail()
            {return bookRetailValue;}    
};  

/*
previous data structure

extern char bookTitle[20][51];
extern char bookISBN[20][14];    
extern char bookAuthor[20][31];
extern char bookPublisher[20][31];
extern char bookDateAdded[20][11]; 
extern int bookQtyOnHand[20];
extern double bookWholesaleValue[20];
extern double bookRetailValue[20];
*/

// Bookdata Object 
    extern BookData invbook;
//Inventory File -> "reports.txt"
    extern fstream bookFile;

//functions for inventory management
    //inventory menu header
        void invMenu();
        void invCheck(int);
        void lookUpBook();
        void addBook();
        void editBook();
        void deleteBook();
        void editInventoryInput(int);
        int findBookIndex(string); 
    //report header
        void reports();
        void reportsCheck(int);
        void repListing();
        void repWholesale();
        void repRetail();
        void repQty();
        void repCost();
        void repAge();
#endif
