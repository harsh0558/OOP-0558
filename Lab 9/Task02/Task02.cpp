#include <iostream>
using namespace std;

class MenuItem{

protected:
    string dishName;
    float price;

public:
    virtual void showDetails() = 0;
    virtual void prepare() = 0;

};

class Appetizer: public MenuItem{

public:
    Appetizer(string name, float p){
        dishName = name;
        price = p;
    }

    void showDetails(){
        cout<<"Appetizer Name: "<<dishName<<endl;
        cout<<"Price: "<<price<<endl;
    }

    void prepare(){
        cout<<"your appetizer is being prepared"<<endl;
    }
};

class MainCourse: public MenuItem{

    public:
    MainCourse(string name, float p){
        dishName = name;
        price = p;
    }

    void showDetails(){
        cout<<"Main Course Name: "<<dishName<<endl;
        cout<<"Price: "<<price<<endl;
    }

    void prepare(){
        cout<<"your main course is being prepared"<<endl;
    }
};


int main(){
    MenuItem* appetizer = new Appetizer("soup", 800);
    MenuItem* mainCourse = new MainCourse("chicken handi", 2200);

    appetizer->showDetails();
    appetizer->prepare();

    cout << endl;

    mainCourse->showDetails();
    mainCourse->prepare();
    return 0;
}