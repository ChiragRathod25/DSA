#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int>& integers) {
    int n = integers.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (integers[j] > integers[j + 1]) {
                // Swap elements if they are in the wrong order
                int temp = integers[j];
                integers[j] = integers[j + 1];
                integers[j + 1] = temp;
            }
        }
    }
}
int main() {
    vector<int> integers;
    // Read integers into th  e vector (you can modify this part)
    int num;
    cout << "Enter integers (enter non-integer to finish): ";
    while (cin >> num) {
        integers.push_back(num);
    }

    // Sort the vector using bubble sort
    bubbleSort(integers);

    // Print the sorted integers
    cout << "Sorted Integers: ";
    for (int i : integers) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}