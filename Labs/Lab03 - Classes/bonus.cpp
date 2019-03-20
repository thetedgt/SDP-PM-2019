#include <iostream>
#include <ctime> // за функцията time()
#include <cstdlib> // за srand() и rand()
using namespace std;

class Die
{
private:
    int sides;
    int face;
    int totalRolls;
    int rolls[100]; // приемам, че зара може да има максимално 100 страни, защото не сме учили динамична памет още

public:
    Die(int numOfSides = 6)
    {
        srand(time(NULL));
        sides = numOfSides;
        face = 0;
        totalRolls = 0;

        for(int i = 0; i < 100; i++) 
            rolls[i] = 0;
    }

    int getSides() const
    {
        return sides;
    }

    int getFace() const
    {
        return face;
    }

    int roll()
    {
        face = rand() % sides + 1;
        rolls[face-1]++;
        totalRolls++;
        return face;
    }

    void printFace() const
    {
        cout << "Face: " << face << endl;
    }

    void statistics() const
    {
        for(int i = 0; i < sides; ++i)
        {
            cout << "Side " << i+1 << " has been rolled " << (double)rolls[i]/totalRolls*100 << "\%\n";
        }
    }
};

int main()
{
    Die die;

    for(int i = 0; i < 100; i++)
    {
        cout << die.roll() << endl;
    }

    die.statistics();

    return 0;
}
