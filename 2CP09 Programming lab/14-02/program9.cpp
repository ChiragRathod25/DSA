#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, float> sequence;
int main(void)
{
    int n;
    string name;
    float frequency;
    cin >> n;
    int i = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        cin >> frequency;
        sequence[name] = frequency;
    }

    // sorting
    map<string, float>::iterator it = sequence.begin();
    for (int i = 0; i < n; i++)
    {
        string s1 = it->first;
        map<string, float>::iterator itr2 = sequence.begin();
        auto it2 = sequence.find(s1);
        for (int j = i; j < n; j++)
        {
            string s2 = itr2->first;
            if (s1.compare(s2) <= 0)
            {
                continue;
            }
            else{
                swap(it, itr2);
            }
                itr2++;
        }
            it++;
    }
    //display
    map<string, float>::iterator dis = sequence.begin();
      for (auto dis = sequence.begin(); dis != sequence.end(); dis++)
            {
                cout << dis->first << '\t'
                    <<dis->second<<endl;
            }

    return 0;
}
