#include <iostream>
#include <cstring>

using namespace std;

bool isPalindrome(char* str)
{
    int len = strlen(str);
    for(int i = 0; i < len/2; i++)
    {
        if(str[i] != str[len-i-1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char str[100] = "testing";
    char str2[100] = "alabala";

    cout << isPalindrome(str) << " " << isPalindrome(str2) << endl;
    return 0;
}