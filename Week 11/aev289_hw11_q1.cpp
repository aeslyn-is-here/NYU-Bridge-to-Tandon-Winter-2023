#include <iostream>
using namespace std;

void printTriangle(int n);
void printOppTriangles(int n);
void printRuler(int n);

int main() {
    cout << "Triangle:"<< endl;
    printTriangle(8);
    cout << endl;
    cout << "Opposite Triangle:"<< endl;
    printOppTriangles(8);
    cout << endl;
    cout<<"Print Ruler:"<<endl;
    print_ruler(8);
    
    return 0;
}

void printTriangle(int n)
{
    
    if (n < 1)
    {
        return;
    } else
    {
        printTriangle(n - 1);
        
        for(int i=0; i<n; i++)
        {
            cout << '*';
           
        }

        cout << endl;
    }
}

void printOppTriangles(int n)
{
    int i;
    if (n < 1) {
        return;
    } else {
        for(i=0; i<n; i++)
        {
            cout << '*';
           
        }

        cout << endl;
        printOppTriangles(n - 1);

        for(i=0; i<n;i++)
        {
            cout << '*';
          
        }

        cout << endl;
    }
}
void printRuler(int n)
{
    if (n < 1)
    {
        return;
    } else
    {
        printRuler(n - 1);

        for (int i = 0; i < n; i++)
        {
            cout << '-';
        }
        cout << endl;
        printRuler(n - 1);
    }
}
