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
                cout << "Vehicle ID: " << Vid << " - Battery Capacity: " << battery_capacity << std::endl;
            }
        }
        else if (Vtype == "HybridTruck")
        {
            size_t cargo_colon = Vextra.find(':');
            size_t pipe = Vextra.find('|');

            if (cargo_colon != string::npos && pipe != string::npos)
            {
                string cargo_str = Vextra.substr(cargo_colon + 1, pipe - cargo_colon - 1);
                int cargo = stoi(cargo_str);

                size_t battery_colon = Vextra.find(':', pipe + 1);
                if (battery_colon != string::npos)
                {
                    string battery_str = Vextra.substr(battery_colon + 1);
                    int battery = stoi(battery_str);
                    cout << "Vehicle ID: " << Vid << " - Cargo: " << cargo << " | Battery: " << battery << endl;
                }
            }
            else
            {
                cout << "Error: Invalid ExtraData format for HybridTruck: " << Vextra << endl;
            }
        }
        else
        {
            cout << "Error: Unknown vehicle type '" << Vtype << "'" << endl;
        }
    }

    return 0;
}