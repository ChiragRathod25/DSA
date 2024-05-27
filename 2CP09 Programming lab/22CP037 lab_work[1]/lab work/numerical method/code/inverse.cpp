#include <iostream>
#include <cmath>
using namespace std;

void display(double matrix[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void make0(double A[3][3], double I[3][3], int row, int col)
{
    double f = A[row][col] / A[col][col];
    for (int j = 0; j < 3; ++j)
    {
        A[row][j] -= A[col][j] * f;
        I[row][j] -= I[col][j] * f;
    }
}

void makeDiagonal1(double A[3][3], double I[3][3], int row, int col)
{
    double f = A[row][col];
    for (int j = 0; j < 3; ++j)
    {
        A[row][j] /= f;
        I[row][j] /= f;
    }
}

void find(double A[3][3], double I[3][3])
{
    make0(A, I, 1, 0);
    make0(A, I, 2, 0);
    make0(A, I, 2, 1);

    make0(A, I, 0, 1);
    make0(A, I, 0, 2);
    make0(A, I, 1, 2);

    makeDiagonal1(A, I, 0, 0);
    makeDiagonal1(A, I, 1, 1);
    makeDiagonal1(A, I, 2, 2);
}

int main()
{
    double A[3][3] = {{2, 1, -1}, {-3, -1, 2}, {-2, 1, 2}}; // Example matrix
    double I[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    cout << "Original Matrix:" << endl;
    display(A);

    find(A, I);

    cout << "Inverse Matrix:" << endl;
    display(I);

    return 0;
}