#include <iostream>
#include <cstring>

using namespace std;

bool sorted(char words[][32], int n)
{
    for(int i = 1; i < n; i++)
    {
        if(strcmp(words[i-1], words[i]) > 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    char words[6][32] = {"photograph", "bulldozer", "flatness", "phantom", "hidden", "crush"};
    char moreWords[5][32] = {"all", "are", "black", "then", "white"};

    cout << sorted(words, 6) << endl;
    cout << sorted(moreWords, 5) << endl;
    return 0;
}