#ifndef general_header
#define general_header

#include <string>
#include <ctime>
//bookinfo header 

void bookInfo(char[], char[], char[], char[], char[], int, double, double);



//cashier header

int cashier();
int ISBNLookup(char []);



//inventory header

//general search function
void search();

//sorting quantity
void qtsort(int []);

//sorting cost
void costSort(int []);

//sorting date
void dateSort(int[]);

//displaye date
void displayDate();

//general integer swap
void swap(int&, int&);


void strUpper(char *word);




    

//connect inventory to entire program
extern char bookTitle[20][51];
extern char isbn[20][14];    
extern char author[20][31];
extern char publisher[20][31];
extern char dateAdded[20][11]; 

    
extern int qtyOnHand[20];
extern double wholeSale[20] ;
extern double retail[20];






//inventory menu header

int invMenu();
void invCheck(int);
void lookUpBook();
void addBook();
void editBook();
void deleteBook();
void readInput(int);
//report header

int reports();
void reportsCheck(int);
void repListing();
void repWholesale();
void repRetail();
void repQty();
void repCost();
void repAge();

#endif
