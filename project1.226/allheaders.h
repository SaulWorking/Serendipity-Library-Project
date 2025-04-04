#ifndef general_header
#define general_header

#include <string>
#include <ctime>
using namespace std;
//general purpose functions/variables


//the amount 

    //prints '-' 100 times
    void separateText();
    //asks for user to press enter
    void forcedUserWait();
    //takes book index and displays bookinfo
    void bookIndexInformation(int);

//bookinfo header 
    //takes book information as argument and regurgitates it
    void bookInfo(char[], char[], char[], char[], char[], int, double, double);
//cashier header

    //prompts user to purchase book
    void cashier();

    //finds index of book ISBN
    int ISBNLookup(std::string);



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

 struct BookData{
     char Title[51];
     char ISBN[14];    
     char Author[31];
     char Publisher[31];
     char DateAdded[11]; 

     int QtyOnHand;     
     double WholesaleValue;
     double RetailValue;


};  

extern BookData invbook[20];

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


//functions for specific subscripts in array


void setTitle(char *, int);	
void setISBN(char *, int);		
void setAuthor(char *, int);		 
void setPub(char *, int);		
void setDateAdded(char *, int);	  
void setQty(int, int);	
void setWholesale(double, int);	 
void setRetail(double, int);
int  isEmpty(int);
void removeBook(int);



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
