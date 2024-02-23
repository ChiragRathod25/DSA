//copy one file to another filename as a command line argument binary file as ascii file
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(int argc, char * argv[])
{

    if(argc!=3)
    {
        cout<<"Enter command line argument";
        return 1;
    }
    ifstream i(argv[1], ios::binary);
    ofstream o(argv[2], ios::binary);
    char ch;
    while(!i.eof())
    {
       i.get(ch);
       if(!i.eof())
       {
       o.put(ch);
       }
    }
    i.close();
    o.close();
}
