#include <iostream>

using namespace std;

int longestSubsequence(char* str)
{
    if(str == nullptr || *str == '\0')
    {
        return 0;
    }

    int curr = 1, maxx = 1;
    for (int i = 1; str[i] != '\0'; ++i)
    {
        if(str[i] == str[i-1])
        {
            curr++;
        }
        else
        {
            if(curr > maxx)
            {
                maxx = curr;
                curr = 1;
            }
        }
    }

    if(curr > maxx)
    {
        maxx = curr;
    }

    return maxx;
}

int main()
{
    char str[100] = "aaacccbdsrrtttttt";
    cout << longestSubsequence(str);
    return 0;
}