#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;
    
    cout << "\nYou have chosen " << n << ", so now insert " << n * n << " elements:\n";

    // Input original matrix
    float arr[n][n];
    float in[n][n];

    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (i == j) {
                in[i][j] = 1;
            } else {
                in[i][j] = 0;
            }
        }
    }

 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                float ratio = arr[j][i] / arr[i][i];
                for (int k = 0; k < n; k++) {
                    arr[j][k] -= ratio * arr[i][k];
                    in[j][k] -= ratio * in[i][k];
                }
            }
        }
    }

 
    for (int i = 0; i < n; i++) {
        float divisor = arr[i][i];
        for (int j = 0; j < n; j++) {
            arr[i][j] /= divisor;
            in[i][j] /= divisor;
        }
    }

   
/*     float threshold = 0.01;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(arr[i][j]) < threshold) {
                arr[i][j] = 0;
            }
            if (abs(in[i][j]) < threshold) {
                in[i][j] = 0;
            }
        }
    }
 */
    // Display original matrix
    cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    // Display inverse matrix
    cout << "\nInverse Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << in[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}