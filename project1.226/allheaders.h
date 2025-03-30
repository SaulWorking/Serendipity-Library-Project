#ifndef general_header
#define general_header

#include <string>
#include <ctime>

//general purpose
void separateText();
void forcedUserWait();


//main menu 

void mainMenu(int);
void optionCheck(int);


//bookinfo header 

void bookInfo(char[], char[], char[], char[], char[], int, double, double);



//cashier header

void cashier();
int ISBNLookup(std::string);



//inventory header

//general search function
void search();

//sorting quantity
void quantitySort(int []);

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
extern char bookISBN[20][14];    
extern char bookAuthor[20][31];
extern char bookPublisher[20][31];
extern char bookDateAdded[20][11]; 

    
extern int bookQtyOnHand[20];
extern double bookWholesaleValue[20] ;
extern double bookRetailValue[20];






//inventory menu header

void invMenu();
void invCheck(int);
void lookUpBook();
void addBook();
void editBook();
void deleteBook();
void readInput(int);
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
