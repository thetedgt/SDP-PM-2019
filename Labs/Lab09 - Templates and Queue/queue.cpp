#include<iostream>
#include<cassert>
#include<cmath>
#include<iomanip>

template<typename T>
struct Node
{
    T value;
    Node* next;

    Node(const T& val, Node* n = nullptr) :
        value(val), next(n)
    {}
};

template<typename T>
class Queue
{
private:
    Node<T> *start, *end;

    void copy(const Queue<T>& other);
    void del();
public:
    Queue();
    Queue(const Queue<T>& other);
    ~Queue();
    Queue<T>& operator=(const Queue<T>& other);

    bool empty();
    void push(const T x);
    void pop();
    T front();
};

template<typename T>
void Queue<T>::copy(const Queue<T>& other)
{
    Node<T> *it = other.start;

    if(!it) return;
    start = end = new Node<T>(it.value);
    it = it->next;

    while(it != nullptr)
    {
        end->next = new Node<T>(it.value);
        end = end->next;
        it = it->next;
    }
}

template<typename T>
void Queue<T>::del() {
    while(!empty()) {
        pop();
    }
}

template<typename T>
Queue<T>::Queue() {
    start = end = nullptr;
}

template<typename T>
Queue<T>::Queue(const Queue<T>& other) {
    if(other.empty()) {
        return;
    }

    Node<T> *it = other.start;
    start = end = new Node<T>(it.value);
    it = it->next;

    while(it != nullptr) {
        end->next = new Node<T>(it.value);
        end = end->next;
        it = it->next;
    }
}

template<typename T>
Queue<T>::~Queue() {
    del();
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
    if(this != &other) {
        del();
        copy(other);
    }
    return *this;
}

template<typename T>
bool Queue<T>::empty() {
    return start == nullptr;
}

template<typename T>
void Queue<T>::push(const T x) {
    if(empty()) {
        start = end = new Node<T>(x);
        return;
    }
    end->next = new Node<T>(x);
    end = end->next;
}

template<typename T>
void Queue<T>::pop() {
    if(empty()) return;

    if(start == end)
    {
        delete start;
        start = end = nullptr;
        return;
    }

    Node<T>* temp = start;
    start = start->next;
    delete temp;
}

template<typename T>
T Queue<T>::front() {
    assert(!empty());

    return start->value;
}

int products235(int n) {
    Queue<int> q2, q3, q5;
    q2.push(2);
    q3.push(3);
    q5.push(5);

    for(int i = 1; i < n; ++i)
    {
        int m = std::min(q2.front(), q3.front());
        m = std::min(m, q5.front());

        if(q2.front() == m) q2.pop();
        if(q3.front() == m) q3.pop();
        if(q5.front() == m) q5.pop();

        q2.push(2*m);
        q3.push(3*m);
        q5.push(5*m);
    }

    int m = std::min(q2.front(), q3.front());
    m = std::min(m, q5.front());
    return m;
}

void binary(int n) {
    Queue<std::string> q;
    q.push("1");
    int len = log2(n) + 1;

    for(int i = 0; i< n; ++i) {
        q.push(q.front() + "0");
        q.push(q.front() + "1");

        std::cout << std::setfill('0') << std::setw(len)<< q.front() << std::endl;
        q.pop();
    }
}

int main()
{
    //std::cout << products235(10) << std::endl;
    binary(16);
    return 0;
}
