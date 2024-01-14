#include <iostream>
#include <cstdlib>
#include <ctime>
 using namespace std;

int main()
{
    int x1, x2, x3, guess;
    int guessNum=4;
    int numGuesses=0;
    int floorRange=1;
    int ceilingRange=100;
    
    srand(time(0));
    
    x1 = rand();
    x2 = rand();
    x3 = x3 = rand() % 100;

    
    cout<<"I thought of a number between 1 and 100! Try to guess it. \n";
    cout<<"Range: [1, 100]. Number of guesses left: "<< guessNum + 1 << endl;
    cout<< "Your guess: ";
    cin >> guess;


    
    while(guess!=x3 && guessNum + 1 > 1) //When the guess is incorrect and the number of guesses left is >1
    {
 
        numGuesses++;
        guessNum--;
        if(guess> x3)
        {
            ceilingRange= guess-1;
            cout<< "Wrong! My number is smaller." << endl;
            cout<< "Range: ["<< floorRange<< ", "<< ceilingRange<< "]. Number of guesses left: "<< guessNum + 1 << endl;
            cout<< "Your guess: ";
            cin >> guess;
        }
        else
        {
            floorRange=guess+1;
            cout<< "Wrong! My number is bigger. "<< endl;
            cout<< "Range: ["<< floorRange<< ", "<< ceilingRange <<"]. Number of guesses left: "<< guessNum + 1 << endl;
            cout<< "Your guess: ";
            cin >> guess;
        }
    }
    
    while (guess!=x3 && guessNum==1)
    {
        guessNum--;
        if(guess> x3)
        {
            ceilingRange= guess-1;
            cout<< "Wrong! My number is smaller." << endl;
            cout<< "Range: ["<< floorRange<< ", "<<ceilingRange<< "]. Number of guesses left: "<< guessNum + 1 << endl;
            cout<< "Your guess: ";
            cin >> guess;
            cout<< endl;
            if(guess !=x3)
            {
                cout<< "Out of guesses! My number is " << x3;
            }
        }
        if(guess <x3)
        {
            floorRange=guess+1;
            cout<< "Wrong! My number is bigger. "<< endl;
            cout<< "Range: ["<< floorRange<< ", "<<ceilingRange <<"]. Number of guesses left: "<< guessNum + 1 << endl;
            cout<< "Your guess: ";
            cin >> guess;
            if(guess !=x3)
            {
                cout << "Out of guesses! My number is " << x3;
            }
        }
    }
    if (guess == x3)
    {
            numGuesses++;
            cout<< "Congratulations! You guessed my number in "<< numGuesses << " guesses.";
    }

    else {
        cout << "Out of guesses! My number is " << x3 << " ";
    }
    
    return 0;
 }
