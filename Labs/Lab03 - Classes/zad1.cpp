#include <iostream>
#include <cstring>

using namespace std;

class Dictionary
{
private:
    static const unsigned MAX_LEN = 100;
    char words[100][32];
    unsigned size;

    int binarySearch(const char* str) const;
public:
    Dictionary() : 
        size(0)
    {}

    void add(const char* str);
    void remove(const char* str);
    bool empty() const;
    bool full() const;
    bool contains(const char* str) const;
    void print() const;
    void printIfSubstr(const char* str) const;
};

int main()
{
    Dictionary dict;

    dict.add("haken");
    dict.add("tool");
    dict.add("metallica");
    dict.add("ghost");
    dict.add("ayreon");

    dict.printIfSubstr("o");
    cout << endl;
    
    dict.print();
    cout << endl;

    dict.remove("ayreon");
    dict.remove("nightwish");
    dict.remove("tool");
    dict.remove("haken");

    dict.print();

    return 0;
}

int Dictionary::binarySearch(const char* str) const
{
    int start = 0, end = size-1;
    int mid = 0;

    while(start <= end)
    {
        mid = start + (end-start)/2;

        int cmp = strcmp(str, words[mid]);
        if(cmp < 0)
        {
            end = mid - 1;
        }
        else if(cmp > 0)
        {
            start = mid + 1;
        }
        else return mid;
    }
    
    // if the word isn't found returns where it needs to be inserted
    if(strcmp(str, words[mid]) > 0) ++mid;
    return mid;
}

void Dictionary::add(const char* str)
{
    if(full())
    {
        cout << "The dictionary is full!\n";
        return;
    }

    if(empty())
    {
        strcpy(words[size++], str);
        return;
    }

    int ind = binarySearch(str);
    if(strcmp(str, words[ind]) == 0)
    {
        cout << "The word \"" << str << "\" is already in the dictionary!\n";
        return;
    }

    size++;
    for(int i = size; i > ind; i--)
    {
        strcpy(words[i], words[i-1]);
    }

    strcpy(words[ind], str);
}

void Dictionary::remove(const char* str)
{
    if(empty())
    {
        cout << "The dictionary is empty!\n";
        return;
    }

    int ind = binarySearch(str);
    if(strcmp(str, words[ind]) != 0)
    {
        cout << "The word \"" << str << "\" is not in the dictionary!\n";
        return;
    }

    size--;
    for(int i = ind; i < size; i++)
    {
        strcpy(words[i], words[i+1]);
    }
}

bool Dictionary::empty() const
{
    return size == 0;
}

bool Dictionary::full() const
{
    return size == MAX_LEN;
}

bool Dictionary::contains(const char* str) const
{
    if(empty()) return false;

    int ind = binarySearch(str);
    return strcmp(str, words[ind]) == 0;
}

void Dictionary::print() const
{
    for(unsigned i = 0; i < size; i++)
    {
        cout << words[i] << endl;
    }
}

void Dictionary::printIfSubstr(const char* str) const
{
    for(unsigned i = 0; i < size; i++)
    {
        if(strstr(words[i], str))
        {
            cout << words[i] << endl;
        }
    }
}

