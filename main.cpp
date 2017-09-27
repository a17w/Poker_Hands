// Annie Wong
// CS110B Assignment 4: Poker Hands

#include <iostream>
using namespace std;

// function prototype

bool containsPair(int hand[]);
bool containsTwoPair(int hand[]);
bool containsThreeOfaKind(int hand[]);
bool containsStraight(int hand[]);
bool containsFullHouse(int hand[]);
bool containsFourOfaKind(int hand[]);
bool containsStraight(int hand[]);


// main function

int main() {

    int card[5] = {}; // declaring the user array
    char playAgain = 'y';

    do // loop to playAgain
    {
        // ask user to input five numeric cards between 2-9
        cout << "Enter five numeric cards, no face cards. Use 2-9" << endl;

        for (int i = 0; i < 5; i++)
        {
            cout << "Card " << i + 1 << ": ";
            cin >> card[i];

            // input validation
            while (card[i] < 2 || card[i] > 9)
            {
                cout << "Please enter a value between 2-9." << endl;
                cout << "Card " << i + 1 << ": ";
                cin >> card[i];
            }
        }

            if (containsFourOfaKind(card))
            {
                cout << "Four of a kind!\n" << endl;
            }
            else if (containsFullHouse(card))
            {
                cout << "Full House!\n" << endl;
            }
            else if (containsStraight(card))
            {
                cout << "Straight!\n" << endl;
            }
            else if (containsThreeOfaKind(card))
            {
                cout << "Three of a kind!\n" << endl;
            }
            else if (containsTwoPair(card))
            {
                cout << "Two Pair!\n" << endl;
            }
            else if (containsPair(card))
            {
                cout << "Pair!\n" << endl;
            }
            else
            {
                cout << "High Card!\n" << endl;
            }

        cout << "Would you like to play again? (y/n): ";
        cin >> playAgain;
        cout << endl;

    } while (playAgain == 'y');
    return 0;
}

// function definition

bool containsFourOfaKind(int hand[])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            for (int k = j + 1; k < 5; k++)
            {
                for (int l = k + 1; l < 5; l++)
                {
                    if (hand[i] == hand[j] && hand[j] == hand[k] && hand[k] == hand[l])
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool containsFullHouse(int hand[])
{
   for (int i = 0; i < 5; i++)
   {
       for (int j = i + 1; j < 5; j++)
       {
           for (int k = j + 1; k < 5; k++)
           {
               for (int m = 0; m < 5; m++)
               {
                   for (int n = m + 1; n < 5; n++)
                   {
                       if (hand[i] == hand[j] && hand[j] == hand[k] && hand[i] != hand[n] && hand[n] == hand[m]){
                           return true;
                       }

                   }
               }

           }
       }
   }
    return false;
}

bool containsTwoPair(int hand[])
{
    int counter = 0;

    for (int i = 0; i < 5; i++)
    {

        for (int j = i + 1; j < 5; j++)
        {
            if (hand[i] == hand[j])
            {
                counter++;
            }
            if (counter == 2)
            {
                return true;
            }
        }
    }
    return false;
}

bool containsThreeOfaKind(int hand[])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            for (int k = j + 1; k < 5; k++)
            {
                if (hand[i] == hand[j] && hand[j] == hand[k])
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool containsPair(int hand[])
{
    for (int i = 0; i < 5; i++)
    {
        for(int j = i+1; j < 5; j++)
        {
            if (hand[i] == hand[j])
            {
                return true;
            }
        }
    }
    return false;
}

bool containsStraight(int hand[])
{
    int swapHolder;
    for (int i = 0; i < 5; i++)
    {
        for (int j=1; j<(5-1); j++)
        {
            if(hand[j-1] > hand[j])
            {
                swapHolder = hand[j];
                hand[j-1] = hand[j];
                hand[j] = swapHolder;
                return true;
            }
        }
    }
    return false;
}
