#include <iostream>
#include <string.h>
#include <cassert>
using namespace std;

class String
{

public:
	String(const char* str = nullptr);
	String(const String& other);
	String& operator=(const String& other);
	~String();


	String operator+(const String & other);
	void removeLastN(size_t n);
	void print() const;
	char largestAscii() const;
	bool isAscending() const;

private:
	char*str;
	int length;
	void copy(const char* str);
	void del();
};

void String::copy(const char* str) {
    if(str != nullptr) {
        this->length = strlen(str);
        this->str = new char[length + 1];
        strcpy(this->str, str);
    } else {
        this->length = 0;
        this->str = nullptr;
    }
}

void String::del() {
    delete this->str;
    this->str = nullptr;
}

String::String(const char *str) {
    this->copy(str);
}

String::String(const String& other) {
    this->copy(other.str);
}

String::~String() {
    this->del();
}

String& String::operator=(const String& other) {
    if(this != &other) {
        this->del();
        this->copy(other.str);
    }
    return *this;
}

String String::operator+(const String &other) {
    String result;
    result.length = this->length + other.length;
    result.str = new char[result.length + 1];
    strcpy(result.str, this->str);
    strcat(result.str, other.str);
    return result;
}

void String::removeLastN(size_t n) {
    if (n > length) {
        cout << "losho" << endl;
        this->del();
    } else if(this->str != nullptr) {
        this->str[this->length - n] = '\0';
        this->length -= n;
    }
}

void String::print() const {
    cout << this->str << endl;
}

char String::largestAscii() const {
    if(this->length >= 1)
    {
        char largest = this->str[0];
        for(int i = 1; i <= this->length; ++i)
        {
            if(largest < this->str[i])
            {
                largest = this->str[i];
            }
        }

        return largest;
    }
    return '\0';
}

bool String::isAscending() const {
    for(int i = 0; i < this->length-1; ++i)
    {
        if(this->str[i+1] <= this->str[i])
        {
            return false;
        }
    }
    return true;
}


int main() {

    String str("alabal"), a("a"), res;
    res = str+a;
    res.print();
    res.removeLastN(3);
    res.print();
    res = res + res;
    res.print();
    cout << res.largestAscii() << endl << a.isAscending();

    return 0;

}
