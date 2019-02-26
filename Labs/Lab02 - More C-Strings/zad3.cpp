#include <iostream>
#include <cstring>

using namespace std;

void shortestAndLongest()
{
    char shortest[100], longest[100], curr[100];
    int shortestLen, longestLen;

    cin >> curr;
    strcpy(longest, curr);
    strcpy(shortest, curr);

    shortestLen = strlen(shortest);
    longestLen = shortestLen;

    cin >> curr;
    while(strcmp(curr, ".") != 0)
    {
        int currLen = strlen(curr);
        if(currLen > longestLen)
        {
            strcpy(longest, curr);
            longestLen = currLen;
        }
        if(currLen < shortestLen)
        {
            strcpy(shortest, curr);
            shortestLen = currLen;
        }
        cin >> curr;
    }

    cout << "Shortest: " << shortest << "\nLongest:" << longest << endl;
}

int main()
{
    shortestAndLongest();
    return 0;
}