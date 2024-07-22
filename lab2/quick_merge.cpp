#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

void quickSort(vector<int>& a, int d, int u) {
    if (d >= u) {
        return;
    }
    int temp = d;
    int pi = a[d];
    int left = d + 1;
    int right = u;

    while (left <= right) {
        while (left <= right && a[left] <= pi) {
            left++;
        }
        while (left <= right && a[right] > pi) {
            right--;
        }
        if (left < right) {
            swap(a[left], a[right]);
        }
    }
    swap(a[temp], a[right]);

    quickSort(a, d, right - 1);
    quickSort(a, right + 1, u);
}

void conquer(vector<int>& a, int si, int mid, int ei) {
    int s = ei - si + 1;
    vector<int> merged(s);
    int idx1 = si;
    int idx2 = mid + 1;
    int x = 0;
    while (idx1 <= mid && idx2 <= ei) {
        if (a[idx1] >= a[idx2]) {
            merged[x++] = a[idx2++];
        } else {
            merged[x++] = a[idx1++];
        }
    }
    while (idx1 <= mid) {
        merged[x++] = a[idx1++];
    }
    while (idx2 <= ei) {
        merged[x++] = a[idx2++];
    }

    for (int i = 0, j = si; i < s; i++, j++) {
        a[j] = merged[i];
    }
}

void divide(vector<int>& a, int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = si + (ei - si) / 2;
    divide(a, si, mid);
    divide(a, mid + 1, ei);
    conquer(a, si, mid, ei);
}

void unsorted(vector<int>& a, int n) {
    int c = 0;
    for (int i = n; i > 0; i--) {
        a[c++] = i;
    }
}

void sorted(vector<int>& a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
}

void random(vector<int>& a, int n) {
    srand(time(0)); // Seed the random number generator
    for (int i = 0; i < n; i++) {
        a[i] = rand();
    }
}

int main() {
    int n;
    cout << "Enter Size: ";
    cin >> n;
    vector<int> a(n);

    cout << "For unsorted:\n";
    unsorted(a, n);
    auto start = high_resolution_clock::now();
    quickSort(a, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "For Quick Sort: " << duration.count() << " ms\n";

    unsorted(a, n);
    start = high_resolution_clock::now();
    divide(a, 0, n - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "For Merge Sort: " << duration.count() << " ms\n";

    cout << "For sorted:\n";
    sorted(a, n);
    start = high_resolution_clock::now();
    quickSort(a, 0, n - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "For Quick Sort: " << duration.count() << " ms\n";

    sorted(a, n);
    start = high_resolution_clock::now();
    divide(a, 0, n - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "For Merge Sort: " << duration.count() << " ms\n";

    cout << "For random:\n";
    random(a, n);
    start = high_resolution_clock::now();
    quickSort(a, 0, n - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "For Quick Sort: " << duration.count() << " ms\n";

    random(a, n);
    start = high_resolution_clock::now();
    divide(a, 0, n - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "For Merge Sort: " << duration.count() << " ms\n";

    return 0;
}