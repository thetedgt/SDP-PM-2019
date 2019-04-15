#include <stack>
#include <iostream>
using namespace std;

bool isAscending(stack<int> st)
{
    if(st.empty()) return true;
    int prev = st.top(), cur;
    st.pop();
    if(st.empty()) return true;

    while(!st.empty())
    {
        cur = st.top();
        st.pop();
        if(prev <= cur) return false;
        prev = cur;
    }
    return true;
}

int main()
{
    stack<int> st;
    for(int i = 0; i < 10; ++i)
    {
        st.push(i);
    }
    st.push(0);
    cout << isAscending(st) << endl;
    return 0;
}
