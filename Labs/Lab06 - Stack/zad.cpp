#include "Stack.h" // our stack

int f(int x, int y, int z)
{
    return (x + 2*y + 3*z) % 10;
}

int g(int x, int y)
{
    return (2*x + 3*y) % 10;
}

int calc(const char *expr)
{
    Stack op, arg;
    int i = 0;
    while(expr[i] != '\0')
    {
        if(expr[i] >= '0' && expr[i] <= '9')
        {
            arg.push(expr[i] - '0');
        }
        else if (expr[i] == 'g' || expr[i] == 'f')
        {
            op.push(expr[i]);
        }
        else if (expr[i] == ')')
        {
            char o = op.top();
            op.pop();
            if(o == 'f')
            {
                int z = arg.top();
                arg.pop();
                int y = arg.top();
                arg.pop();
                int x = arg.top();
                arg.pop();
                arg.push(f(x, y, z));
            }
            else if (o == 'g')
            {
                int y = arg.top();
                arg.pop();
                int x = arg.top();
                arg.pop();
                arg.push(g(x, y));
            }
        }
        i++;
    }
    return arg.top();
}


int main()
{
    std::cout << calc("g(5, f(7,3,4))") << std::endl;
    return 0;
}