// copy one file to another file
// filename as a command line argument
// binary file as a ASCII file
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Enter command line argument";
        exit(0);
    }
    ifstream in;
    in.open(argv[1]);
    ofstream out;
    out.open(argv[2]);
    char ch;

    while (in.read((char *)&ch, sizeof(ch)))
    {
        if (!in.eof())
        {
            out.write((char *)&ch, sizeof(ch));
        }
    }

    return 0;
}

//subject,marks find min and variants 