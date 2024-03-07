#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int compute_cost(int x) {
    return pow(2, x);
}

bool contains_ten(string binary) {
    int n = binary.length();
    for (int i = 0; i < n - 1; i++) {
        if (binary[i] == '1' && binary[i + 1] == '0') {
            int j = i + 2;
            while (j < n && binary[j] == '0') {
                j++;
            }
            if (j < n && binary[j] == '1') {
                return true;
            }
        }
    }
    return false;
}

string to_binary(int n) {
    string binary;
    while (n != 0) {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    return binary;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string binary = to_binary(n);

        if (!contains_ten(binary)) {
            cout << "0" << endl;
        } else {
            int x = 0;
            int ary_cost = compute_cost(x);
            int total_cost = n + ary_cost;

            while (contains_ten(to_binary(total_cost))) {
                x++;
                ary_cost = compute_cost(x);
                total_cost = n + ary_cost;
            }
            cout << ary_cost << endl;
        }
    }

    return 0;
}
