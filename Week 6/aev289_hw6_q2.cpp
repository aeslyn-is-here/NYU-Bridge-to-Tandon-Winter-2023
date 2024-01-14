#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);

void printPineTree(int n, char symbol);

int main()
{
    int numTri;
    char symbol;

    cout << "Enter the number of triangles to print: ";
    cin >> numTri;
    cout << "Enter a symbol: ";
    cin >> symbol;

    printPineTree(numTri, symbol);

    return 0;
}

void printShiftedTriangle(int n, int m, char symbol)
{
    char space=' ';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << space;
        }

        for (int k = 1; k <= n - i; k++)
        {
            cout << space;
        }

        for (int c = 1; c <= 2 * i - 1; c++)
        {
            cout << symbol;
        }

        cout << endl;
    }
}

void printPineTree(int n, char symbol)
{
    for (int i = 1; i <= n; i++)
    {
        printShiftedTriangle(i + 1, n - i, symbol);
    }
}
