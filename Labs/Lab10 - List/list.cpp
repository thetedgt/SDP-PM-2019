#include <iostream>

using namespace std;

template<typename T>
struct Node
{
  T data;
  Node<T>* prev, *next;

  Node(T d = 0, Node<T>* p = nullptr, Node<T>* n = nullptr) :
    data(d), prev(p), next(n)
  {}
};



template<typename T>
class List
{
private:
  Node<T>* m_start, *m_end;

  void copy(const List<T>& other);
  void del();
public:
  class Iterator {
    private:
      Node<T> *curr;

    public:
      friend class List;
      Iterator(Node<T> *it) {
        curr = it;
      }

      void operator++() {
        if(curr) {
          curr = curr->next;
        }
      }

      void operator--() {
        if(curr) {
          curr = curr->prev;
        }
      }

      T& operator*() const {
        return curr->data;
      }

      bool operator==(const Iterator &it) {
        return curr == it.curr;
      }

      bool operator!=(const Iterator &it) {
        return curr != it.curr;
      }
  };

  List();
  List(const List<T>& other);
  ~List();
  List<T>& operator=(const List<T>& other);

  bool empty() const;
  void push_back(const T& a);
  void push_front(const T& a);
  // void insert(const T& a, );
  void pop_front();
  void pop_back();
  // void remove();

  int size() const;
  T front() const;
  T back() const;
  Iterator begin() {
    return Iterator(this->m_start);
  }
  Iterator end() {
    return Iterator(this->m_end->next);
  }
  
};

int main() {
  List<int> list;
  list.push_back(4);
  list.push_back(7);
  list.push_back(8);

  List<int>::Iterator it = list.begin();
  while(it != list.end()) {
    cout  << *it << endl;
    ++it;
  }

  return 0;
}

template<typename T>
void List<T>::copy(const List<T>& other)
{
  if(other.empty())
  {
    m_start = m_end = nullptr;
  }
  else
  {
    Node<T>* it = other.m_start;
    Node<T>* cur = new Node<T>(it->data, nullptr, nullptr);
    m_start = cur;
    it = it->next;
    while(it != nullptr)
    {
      cur->next = new Node<T>(it->data, cur, nullptr);
      cur = cur->next;
      it = it->next;
    }
    m_end = cur;
  }
}

template<typename T>
void List<T>::del()
{
  while(m_start != nullptr)
  {
    Node<T>* cur = m_start;
    m_start = m_start->next;
    delete cur;
  }
  m_end = nullptr;
}

template<typename T>
List<T>::List()
{
  m_start = nullptr;
  m_end = nullptr;
}

template<typename T>
List<T>::List(const List<T>& other)
{
  copy(other);
}

template<typename T>
List<T>::~List()
{
  del();
}

template<typename T>
List<T>& List<T>::operator=(const List<T> &other)
{
  if(this != &other)
  {
    del();
    copy(other);
  }
  return *this;
}

template<typename T>
bool List<T>::empty() const
{
  return m_start == nullptr || m_end == nullptr;
}

template<typename T>
void List<T>::push_back(const T& a)
{
  m_end = new Node<T>(a, m_end, nullptr);
  if(this->empty())
  {
    m_start = m_end;
  }
  else
  {
    m_end->prev->next = m_end;
  }
}

template<typename T>
void List<T>::push_front(const T& a)
{
  m_start = new Node<T>*(a, nullptr, m_start);
  if(this->empty())
  {
    m_end = m_start;
  }
  else
  {
    m_start->next->prev = m_start;
  }
}

// void insert(const T& a, );

template<typename T>
void List<T>::pop_front()
{
  if(!this->empty())
  {
    Node<T>* cur = m_start;
    m_start = m_start->next;
    delete cur;
  }
  if(this->empty()) m_end = nullptr;
}

template<typename T>
void List<T>::pop_back()
{
  if(!this->empty())
  {
    Node<T>* cur = m_end;
    m_end = m_end->prev;
    delete cur;
  }
  if(this->empty()) m_start = nullptr;
}
// void remove();

template<typename T>
int List<T>::size() const
{
  int s = 0;
  Node<T>* cur = m_start;
  while(cur != nullptr)
  {
    ++s;
    cur = cur->next;
  }
}

template<typename T>
T List<T>::front() const
{
  if(this->empty()) exit(1);
  return m_start->data;
}

template<typename T>
T List<T>::back() const
{
  if(this->empty()) exit(1);
  return m_end->data;
}