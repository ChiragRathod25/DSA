#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> ob;
    for(int i = 1; i <= 10; i++)
        ob.push_back(i);
    int index, ele;
    cout << "Enter index and value : ";
    cin >> index >> ele;
    list<int>::iterator iter = ob.begin();

    // insert
    for (int i = 0; i < index; i++)
        iter++;
    ob.insert(iter, ele);

    // delete
    cout << "Enter number to delete : ";
    cin >> ele;
    for (iter = ob.begin(); iter != ob.end(); iter++)
        if (*iter == ele)
            break;
    if (*iter == ele)
        ob.erase(iter);

    // insert_at_end
    iter = ob.end();
    cout << "Enter element to insert at end : ";
    cin >> ele;
    ob.insert(iter, ele);

    // sort
    ob.sort();

    //pop
    ob.pop_back();

    //reverse
    ob.reverse();

    // print
    for (iter = ob.begin(); iter != ob.end(); iter++)
        cout << *iter << " ";
    return 0;
}