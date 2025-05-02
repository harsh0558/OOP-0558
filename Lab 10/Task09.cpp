#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inFile("large_log.txt");

    if (!inFile)
    {
        cerr << "Error unable to open large_log.txt" << endl;
        return 1;
    }

    int BUFFER_SIZE = 10;
    char buffer[BUFFER_SIZE + 1];

    if (inFile.read(buffer, BUFFER_SIZE))
    {
        buffer[BUFFER_SIZE] = '\0';
        cout << "First 10 characters: " << buffer << endl;
        cout << "Position after first read: " << inFile.tellg() << endl;
    }

    if (inFile.read(buffer, BUFFER_SIZE))
    {
        buffer[BUFFER_SIZE] = '\0';
        cout << "Next 10 characters: " << buffer << endl;
        cout << "Position after second read: " << inFile.tellg() << endl;
    }

    inFile.close();
    return 0;
}
