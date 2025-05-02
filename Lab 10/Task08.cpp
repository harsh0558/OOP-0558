#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int SIZE = 5;

    ofstream outFile("config.txt");
    if (!outFile)
    {
        cerr << "Error creating file." << endl;
        return 1;
    }
    outFile << "AAAAABBBBBCCCCC";
    outFile.close();

    fstream file("config.txt", ios::in | ios::out);
    if (!file)
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    file.seekp(SIZE, ios::beg);
    file << "XXXXX";

    file.seekg(0, ios::beg);
    string content;
    getline(file, content);

    file.close();

    cout << "Updated file content: " << content << endl;

    return 0;
}
