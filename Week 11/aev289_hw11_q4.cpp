#include <iostream>
using namespace std;

int lowestCost(int arr[], int size);
int main()
{
    
    const int BOARDSZ=6;
    int board[BOARDSZ]={0, 3, 80, 6, 57,10};
    int lowCost= lowestCost(board, BOARDSZ);
    cout<< "Lowest cost of game: $"<< lowCost<<".\n";
    
    
    
    return 0;
}
int lowestCost(int arr[], int size)
{
    if (size <= 3)
    {
        return arr[size - 1];
    } else
    {
        int steps1= lowestCost(arr, size - 1);
        
        int steps2 = lowestCost(arr, size - 2);

        if (steps1 < steps2)
        {
            return steps1 + arr[size - 1];
        } else
        {
        return steps2 + arr[size - 1];
        }
    }
}
