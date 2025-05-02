#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    ifstream file("Vehicels.txt");
    string line;

    while (std::getline(file, line))
    {
        istringstream iss(line);
        string Vtype, Vid, Vname, Vyear, Vextra, Vcert;

        getline(iss, Vtype, ',');
        getline(iss, Vid, ',');
        getline(iss, Vname, ',');
        getline(iss, Vyear, ',');
        getline(iss, Vextra, ',');
        getline(iss, Vcert, ',');

        int year_num = stoi(Vyear);

        cout << "Type: " << Vtype << "\n";
        cout << "ID: " << Vid << "\n";
        cout << "Name: " << Vname << "\n";
        cout << "Year: " << year_num << "\n";
        cout << "ExtraData: " << Vextra << "\n";
        cout << "Certification: " << Vcert << "\n";

        if (Vtype == "AutonomousCar")
        {
            size_t colon_pos = Vextra.find(':');
            if (colon_pos != string::npos)
            {
                string version_str = Vextra.substr(colon_pos + 1);
                float software_version = stof(version_str);
                cout << "Vehicle ID: " << Vid << " - Software Version: " << software_version << endl;
            }
        }
        else if (Vtype == "ElectricVehicle")
        {
            size_t colon_pos = Vextra.find(':');
            if (colon_pos != string::npos)
            {
                string capacity_str = Vextra.substr(colon_pos + 1);
                int battery_capacity = stoi(capacity_str);
                cout << "Vehicle ID: " << Vid << " - Battery Capacity: " << battery_capacity << endl;
            }
        }
    }

    return 0;
}