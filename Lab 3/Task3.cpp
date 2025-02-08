#include <iostream>
using namespace std;

class Library{
private:
    string bookList[100];
    string borrowedBooks[100];
    string avaliableBooks[100];
public:
    Library(){
        for(int i = 0; i < 100; i++){
            bookList[i] = "";
            borrowedBooks[i] = "";
            avaliableBooks[i] = "";
        }
    }

    void addBook(string bookName){
        for(int i = 0; i < 100; i++){
            if(bookList[i] == ""){
                bookList[i] = bookName;
                break;
            }
        }
    }

    void lendBook(string bookName){
        for(int i = 0; i < 100; i++){
            if(bookList[i] == bookName){
                borrowedBooks[i] = bookName;
                bookList[i] = "";
                break;
            }
        }
    }

    void returnBook(string bookName){
        for(int i = 0; i < 100; i++){
            if(borrowedBooks[i] == bookName){
                bookList[i] = bookName;
                borrowedBooks[i] = "";
                break;
            }
        }
    }
};

int main(){
    Library library;
    library.addBook("Book1");
    library.addBook("Book2");
    library.addBook("Book3");
    library.lendBook("Book1");
    library.lendBook("Book2");
    library.returnBook("Book1");

    return 0;
}