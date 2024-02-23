#include <iostream>
#include <list>
using namespace std;
void display(list<int> &lst)
{
    list<int>::iterator p;
    for (p = lst.begin(); p != lst.end(); ++p)
    {
        cout << *p << " ";
    }
    cout << endl;
}
void remove_first(list<int> &lst, int temp)
{
    list<int>::iterator p;
    int i = 0;
    for (p = lst.begin(); p != lst.end(); ++p)
    {
        i++;
        if (temp == *p)
        {
            lst.erase(p);
        }
    }
}
int main()
{
    list<int> list1;
    int temp, index;
    list1.push_back(12);
    list1.push_back(43);
    list1.push_back(22);
    // append
    cout<<"Enter value to append : ";
    cin >> temp;
    list1.push_back(temp);
    // display
    display(list1);
    // insert at position
    list<int>::iterator p;
    cout << "Enter index and value to insert :";
    cin >> index >> temp;
    int i = 0;
    for (p = list1.begin(); p != list1.end(); ++p)
    {
        i++;
        if (i == index)
        {
            break;
        }
    }
    list1.insert(p, temp);
    display(list1);
    // remove
    cout << "Enter Value to remove : ";
    cin >> temp;
    list1.remove(temp);
    display(list1);
    // sort
    list1.sort();
    display(list1);
    // pop last element
    list1.pop_back();
    display(list1);
    //reverse
    list1.reverse();
    display(list1);
    return 0;
}