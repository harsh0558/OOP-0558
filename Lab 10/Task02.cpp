#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    ifstream file("Vehicels.txt");
    string line;

    while (getline(file, line))
    {
        istringstream iss(line);
        string Vtype, Vid, Vname, Vyear, Vextra, Vcert;

        getline(iss, Vtype, ',');
        getline(iss, Vid, ',');
        getline(iss, Vname, ',');
        getline(iss, Vyear, ',');
        getline(iss, Vextra, ',');
        getline(iss, Vcert, ',');

        cout << "Type: " << Vtype << "\n";
        cout << "ID: " << Vid << "\n";
        cout << "Name: " << Vname << "\n";
        cout << "Year: " << Vyear << "\n";
        cout << "ExtraData: " << Vextra << "\n";
        cout << "Certification: " << Vcert << "\n";
    }

    return 0;
}