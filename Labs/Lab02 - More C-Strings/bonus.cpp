#include <iostream>
#include <cstring>

using namespace std;

bool calc(char*& str)
{
    if(*str == 't')
    {
        ++str;
        return true;
    }
    if(*str == 'f') 
    {
        ++str;
        return false;
    }

    if(*str == 'A')
    {
        str += 2; // A(
        bool first = calc(str);
        ++str; // ,
        bool second = calc(str);
        ++str; // )

        return first && second;
    }

    if(*str == 'O')
    {
        str += 2; // O(
        bool first = calc(str);
        ++str; // ,
        bool second = calc(str);
        ++str; // )

        return first || second;
    }
}

bool isCorrect(char*& str)
{
    if(*str == 't' || *str == 'f')
    {
        ++str;
        return true;
    }

    if(*str == 'A' || *str == 'O')
    {
        ++str;
        if(*str != '(')
            return false;
        ++str;

        bool first = isCorrect(str);
        if(!first)
            return false;

        if(*str != ',')
            return false;
        ++str;

        bool second = isCorrect(str);
        if(!second)
            return false;

        if(*str != ')')
            return false;
        ++str; // )

        return true;
    }

    return false;
}

int main()
{
    char str[] = ")A(t,t";//"A(O(f,A(t,t)),A(f,f)))))";
    //cin >> str;
    char *p = str;
    //cout << calc(p);
    p = str;
    cout << p << "\n" << isCorrect(p) << "\n";
    return 0;
}
