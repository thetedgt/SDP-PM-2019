#include <iostream>

using namespace std;

int length(char* str)
{
    int len = 0;
    while(str[len] != '\0')
    {
        len++;
    }
    return len;
}

int lengthRecursive(char* str)
{
    if(*str == '\0')
    {
        return 0;
    }
    return 1 + lengthRecursive(str + 1);
}

int main()
{
    char str[100] = "testing";
    cout << length(str) << " " << lengthRecursive(str) << endl;
    return 0;
}