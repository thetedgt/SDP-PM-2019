#include <iostream>
using namespace std;

const int N = 5;

class MathVector
{
private:
    int arr[N];
public:
    MathVector();
    MathVector(const MathVector& other);
    MathVector& operator=(const MathVector& other);

    MathVector operator+(const MathVector& b) const;
    MathVector operator*(int scalar) const;
    friend MathVector operator*(int scalar, const MathVector& v);

    int& operator[](int index);
    const int& operator[](int index) const;

    friend istream& operator>>(istream& in, MathVector& v);
    friend ostream& operator<<(ostream& out, const MathVector& v);

    bool operator<(const MathVector& v) const;
    operator bool() const;

    MathVector& operator++(); /// ++v
    MathVector operator++(int); /// v++
};

MathVector& MathVector::operator++()
{
    for(int i = 0; i < N; ++i)
    {
        ++arr[i];
    }

    return *this;
}

MathVector MathVector::operator++(int)
{
    MathVector temp = *this;

    for(int i = 0; i < N; ++i)
    {
        ++arr[i];
    }

    return temp;
}

MathVector::operator bool() const
{
    for(int i = 0 ; i < N; ++i)
    {
        if(arr[i] != 0)
            return true;
    }

    return false;
}

bool MathVector::operator<(const MathVector& v) const
{
    unsigned long long len1 = 0, len2 = 0;
    for(int i = 0; i < N; ++i)
    {
        len1 += arr[i]*arr[i];
        len2 += v.arr[i] * v.arr[i];
    }

    return len1 < len2;
}

ostream& operator<<(ostream& out, const MathVector& v)
{
    out << "( ";
    for(int i = 0; i < N-1; ++i)
    {
        out << v.arr[i] << ", ";
    }
    out << v.arr[N-1] << ")\n";

    return out;
}

istream& operator>>(istream& in, MathVector& v)
{
    for(int i = 0; i < N; ++i)
    {
       in >> v.arr[i];
    }

    return in;
}

int& MathVector::operator[](int index)
{
    if(index >= N || index < 0)
    {
        cout << "Segmentation fault\n";
        exit(1);
    }
    return arr[index];
}

const int& MathVector::operator[](int index) const
{
    if(index >= N || index < 0)
    {
        cout << "Segmentation fault\n";
        exit(1);
    }
    return arr[index];
}

MathVector operator*(int scalar, const MathVector& v)
{
    MathVector temp;
    for(int i = 0; i < N; ++i)
    {
        temp.arr[i] = v.arr[i] * scalar;
    }

    return temp;
}

MathVector MathVector::operator*(int scalar) const
{
    MathVector temp;
    for(int i = 0; i < N; ++i)
    {
        temp.arr[i] = arr[i] * scalar;
    }

    return temp;
}

MathVector MathVector::operator+(const MathVector& b) const
{
    MathVector temp;
    for(int i = 0; i < N; ++i)
    {
        temp.arr[i] = arr[i] + b.arr[i];
    }

    return temp;
}

MathVector::MathVector()
{
    for(int i = 0; i < N; ++i)
    {
        arr[i] = 0;
    }
}

MathVector::MathVector(const MathVector& other)
{
    for(int i = 0; i < N; ++i)
    {
        arr[i] = other.arr[i];
    }
}

MathVector& MathVector::operator=(const MathVector& other)
{
    if(this != &other)
    {
        for(int i = 0; i < N; ++i)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}


int main()
{
    MathVector a, c;
    int b = 7;
    a[4] = 3;
    if(a)
    {
        cout << "a is not null\n";
    }
    if(c)
    {
        cout << "c is not null";
    }
    cout << (++c) << "\n" << (c++) << "\n" << c;


    return 0;
}
