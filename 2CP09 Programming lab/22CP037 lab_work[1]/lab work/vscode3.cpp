#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

fstream file;

class emp
{
    char name[20];
    char id[10];
    int salary;
    bool active;

public:
    emp() {}
    emp(char *a, char *b, int c)
    {
        strcpy(name, a);
        strcpy(id, b);
        salary = c;
        active = true;
    }
    void read()
    {
        file.open("data2.txt", ios::in | ios::out);
        emp e;
        while (file.read((char *)&e, sizeof(e)))
        {
            cout << e.name << " " << e.id << " " << e.salary << endl;
        }
    }
};

int main()
{
    class emp e;
    e.read();
    return 0;
}