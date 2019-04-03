#include "Stack.h"

void Stack::copy(const Stack& other)
{
    this->capacity = other.capacity;
    this->size = other.size;
    this->arr = new int[capacity];

    for(int i = 0; i < size; ++i)
    {
        this->arr[i] = other.arr[i];
    }
}

void Stack::del()
{
    delete[] arr;
}

Stack::Stack()
{
    capacity = 4;
    size = 0;
    arr = new int[capacity];
}

Stack::~Stack()
{
    del();
}

Stack::Stack(const Stack& other)
{
    copy(other);
}

Stack& Stack::operator=(const Stack& other)
{
    if(this != &other)
    {
        del();
        copy(other);
    }
    return *this;
}

bool Stack::empty() const
{
    return size == 0;
}

void Stack::push(int x)
{
    if(size >= capacity)
    {
        capacity = 2*capacity;
        int *temp = arr;
        arr = new int[capacity];

        for(int i = 0; i < size; i++)
        {
            arr[i] = temp[i];
        }

        delete[] temp;
    }

    arr[size] = x;
    size++;
}

void Stack::pop()
{
    if(!empty())
    {
        size--;
    }
}

int Stack::top() const
{
    assert(!empty());
    return arr[size-1];
}

void Stack::print() const
{
    for(int i = size-1; i >= 0; --i)
    {
        std::cout << arr[i] <<" ";
    }
    std::cout << std::endl;
}

