#include <iostream>
//#include "MagdaStack.h"
#include <stack>
using namespace std;

bool isElemInStack(stack<int> st, int elem)
{
    while(!st.empty())
    {
        int cur;
        cur = st.top(); /// st.pop(cur);
        if(cur == elem)
        {
            return true;
        }
        st.pop(); /// ne trqbva za Magda stack
    }
    return false;
}

bool contains(stack<int> a, stack<int> b)
{
    while(!a.empty())
    {
        int cur;
        cur = a.top();
        a.pop();

        if(!isElemInStack(b, cur))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    stack<int> st, st2, st3;
    for(int i = 0; i< 10; ++i)
    {
        st.push(i);
        st2.push(i);
        st3.push(i);
    }
    st3.push(20);

    //cout << isElemInStack(st, 5) << "\n" << isElemInStack(st, 20) << endl;
    cout << contains(st2, st) << " " << contains(st3, st) << endl;

    return 0;
}
