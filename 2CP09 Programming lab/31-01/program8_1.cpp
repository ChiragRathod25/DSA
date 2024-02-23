#include <iostream>
#include <vector>
using namespace std;
class Object {
    public:
    double value;
    double weight;
    double ratio;
    // Constructor to initialize values and compute ratio
    Object(double v, double w) : value(v), weight(w), ratio(v / w) {}
};
int main() {
    int N;
    cout << "Enter the number of objects: ";
    cin >> N;
    vector<Object> objects;
    cout << "Enter value and weight of each object:" << endl;
    for (int i = 0; i < N; ++i) {
        double value, weight;
        cout << "Object " << i + 1 << ": ";
        cin >> value >> weight;
        objects.push_back(Object(value, weight));
    }
    // Sort based on value/weight ratio
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (objects[j].ratio < objects[j + 1].ratio) {
                swap(objects[j], objects[j + 1]);
            }
        }
    }
    // Printing the sorted objects based on value/weight ratio
    cout << "Objects sorted based on value/weight ratio:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "Object " << i + 1 << ": Value = " << objects[i].value << ", Weight = " << objects[i].weight << ", Ratio = " << objects[i].ratio << endl;
    }
    return 0;
}
