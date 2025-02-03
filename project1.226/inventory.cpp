#include <fstream>


//ifstream -> you read
//ofstream -> you write
void inventoryCheck(){

std::ofstream writeFile;
std::ifstream readFile;

writeFile.open("report.txt");
readFile.open("report.txt");



writeFile.close();
readFile.close();



    return;
}