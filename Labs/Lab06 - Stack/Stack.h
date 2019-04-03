#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cassert>

class Stack
{
private:
    int *arr;
    int capacity, size;

    void copy(const Stack& other);
    void del();
public:
    Stack();
    ~Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);

    void push(int x);
    void pop();
    int top() const;
    bool empty() const;
    void print() const;
};

#endif