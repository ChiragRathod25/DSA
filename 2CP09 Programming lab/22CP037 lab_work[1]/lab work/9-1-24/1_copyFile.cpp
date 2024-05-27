#include <iostream>
#include <fstream>
using namespace std;

int main(int argv, char *argc[])
{
    fstream in;
    fstream out;
    in.open(argc[1], ios::binary|ios::in);
    out.open(argc[2], ios::binary|ios::out);
    char ch;
    while (!in.eof())
    {
        in.read((char *)&ch, sizeof(ch));
        if (!in.eof())
            out.write((char *)&ch, sizeof(ch));
    }
    return 0;
}