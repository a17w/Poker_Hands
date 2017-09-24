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

int main()
{

    // declaring the user array
    int card[5] = {};

    // ask user to input five numeric cards between 2-9
    cout << "Enter five numeric cards, no face cards. Use 2-9" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "Card " << i+1 << ": ";
        cin >> card[i];
    }

    if (containsThreeOfaKind(card) == true)
    {
        cout << "Three of a Kind" << endl;
    }

    /*
    if (containsTwoPair(card) == true)
    {
        cout << "Two pairs!" << endl;
    }
    */

    /*
    if (containsPair(card) == true)
    {
        cout << "Pair!" << endl;
    }
     */



    return 0;
}


// function definition

bool containsPair(int hand[])
{
    int counter = 0;
    bool pair = false;

    for (int i = 0; i < 5; i++)
    {
        for(int j = i+1; j < 5; j++)
        {
            if (hand[i] == hand[j])
            {
                    counter++;
                if (hand[i] == hand[j] && counter == 1)
                {
                    pair = true;
                }
            }
        }
    }
    return pair;
}


bool containsTwoPair(int hand[])
{
    int counter = 0;
    bool twoPair = false;

    for (int i = 0; i < 5; i++)
    {
        for (int j = i+1; j < 5; j++)
        {
            if (hand[i] == hand[j])
            {
                counter++;
                if (hand[i] == hand[j] && counter == 2)
                {
                    twoPair = true;
                }
            }
        }
    }
    return twoPair;

}

bool containsThreeOfaKind(int hand[])
{
    int counter = 0;
    bool threeOfaKing = false;

    for (int i = 0; i < 5; i++)
    {
        for (int j = i+1; i < 5; j++)
        {
            for (int k = j+1; k < 5; k++)
            {
                if (hand[i] == hand[j] && hand[j] == hand[k])
                {
                    counter++;
                    if (hand[i] == hand[j] && hand[j] == hand[k] && counter == 3)
                    {
                        threeOfaKing = true;
                    }
                }
            }
        }
    }
    return threeOfaKing;
}

bool containsStraight(int hand[])
{


}

bool containsFullHouse(int hand[])
{


}

bool containsFourOfaKind(int hand[])
{


}

bool highCard(int hand[])
{

}