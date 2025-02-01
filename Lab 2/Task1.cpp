#include <iostream>
using namespace std;

struct Books {
    string title;
    string author;
    int year;
};

int main (){
    int numOfBooks;
    cout<<"enter the number of bookes: ";
    cin>>numOfBooks;

    Books *books = new Books[numOfBooks];

    for(int i=0;i<numOfBooks;i++){
        cout<<"enter the title of the book "<< i+1<<" : ";
        cin>>books[i].title;

        cout<<"enter the author of the book "<< i+1<<" : ";
        cin>>books[i].author;

        cout<<"enter the year of the book "<< i+1<<" : ";
        cin>>books[i].year;

    }

    int year;

    cout<<"enter the year: ";
    cin>>year;
    cout<<"\n";

    for(int i=0;i<numOfBooks;i++){
        if(books[i].year>year){
            cout<<"title: "<<books[i].title<<endl;
            cout<<"author: "<<books[i].author<<endl;
            cout<<"yar: "<<books[i].year<<endl;
            cout<<"\n";
        }
    }


    delete [] books;

    return 0;
}