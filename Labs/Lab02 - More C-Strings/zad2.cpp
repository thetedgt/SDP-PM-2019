#include <iostream>
#include <cstring>

using namespace std;

int countOccurances(char* str, char* sub)
{
    char* temp = strstr(str, sub);
    if(temp == nullptr)
    {
        return 0;
    }

    return 1 + countOccurances(temp + 1, sub);
}

int main()
{
    char str[100] = "alabala", sub[100] = "la";
    cout << countOccurances(str, sub);
    return 0;
}