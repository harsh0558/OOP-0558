#include <iostream>
#include <cstring>
using namespace std;

class Appartment{
private:
    int id;
    string address;
    char * owner;

public:
    Appartment(int id, string address, const char * owner){
        this->id = id;
        this->address = address;
        this->owner = new char[strlen(owner) + 1];
        strcpy(this->owner, owner);
    }

    Appartment(const Appartment & obj){
        this->id = obj.id;
        this->address = obj.address;
        this->owner = new char[strlen(obj.owner) + 1];
        strcpy(this->owner, obj.owner);
    }

    void details(){
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Owner: " << owner << endl;
    }

    void setId(int id){
        this->id = id;
    }

    void setAddress(string address){
        this->address = address;
    }

    void setOwner(const char * owner){
        delete[] this->owner;
        this->owner = new char[strlen(owner) + 1];
        strcpy(this->owner, owner);
    }
};

int main(){
    Appartment apt1(100, "karachi", "harsh");
    Appartment apt2(apt1);

    cout << "-----details of appartment 1 before changing the values-----" << endl;
    apt1.details();
    cout << "\n";

    cout << "-----details of appartment 2 before changing the values-----" << endl;
    apt2.details();
    cout << "\n";

    apt2.setId(101);
    apt2.setAddress("lahore");
    apt2.setOwner("khubaib");

    cout << "-----details of appartment 1 after changing the values-----" << endl;
    apt1.details();
    cout << "\n";

    cout << "-----details of appartment 2 after changing the values-----" << endl;
    apt2.details();

    return 0;
}
