#include <iostream>
#include <cstring>

using namespace std;

bool contains(char words[][32], int n, char str[])
{
    for(int i = 0; i < n; i++)
    {
        if(strcmp(words[i], str) == 0)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    char words[6][32] = {"photograph", "bulldozer", "flatness", "phantom", "hidden", "crush"};
    char str1[] = "phantom";
    char str2[] = "blaze";

    cout << contains(words, 6, str1) << endl;
    cout << contains(words, 6, str2) << endl;
    return 0;
}