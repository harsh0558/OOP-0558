#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    ifstream inputFile("data_records.txt", ios::binary);

    if (!inputFile)
    {
        cerr << "Error unable to open data_records.txt\n";
        return 1;
    }

    int OFFSET = 20;
    inputFile.seekg(OFFSET, std::ios::beg);

    string recordLine;
    getline(inputFile, recordLine);

    cout << "Third record: " << recordLine << '\n';

    inputFile.close();
    return 0;
}
