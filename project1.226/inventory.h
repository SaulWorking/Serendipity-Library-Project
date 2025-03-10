#ifndef inventory
#define inventory

#include <string>
#include <ctime>

void search();
void qtsort(int []);
void costSort(int []);
void dateSort(int[]);
void displayDate();
void swap(int&, int&);



extern std::string bookTitle[20];
extern std::string isbn[20];
extern std::string author[20];
extern  std::string publisher[20];
extern std::string dateAdded[20];   

    
extern int qtyOnHand[20];
extern double wholeSale[20] ;
extern double retail[20];



#endif
