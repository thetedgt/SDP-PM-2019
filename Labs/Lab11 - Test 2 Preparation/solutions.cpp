// решения на няколко примерните задачи за второто контролно

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <list>

using namespace std;

// 1.1 б)
bool isInQueue(int a, queue<int>& q )
{
  if(q.empty())
    return false;
  int temp = q.front();
  q.pop();
  return temp == a || isInQueue(a, q);
}

// 3.1 б)
bool areWordsSorted(queue<string>& q)
{
  if(q.empty())
    return true;
  string top = q.front();
  q.pop();
  if(q.empty())
    return true;
  return top <= q.front() && areWordsSorted(q);
}

// 2.2
struct Student {
  string name;
  int facN;
  int kurs;

  friend ostream& operator<<(ostream& out, const Student &stud) {
    out << stud.name << " " << stud.facN << " " << stud.kurs << endl;
    return out;
  }
};

void studs1(list<Student> &students) {
  auto it = students.begin();
  stack<Student> s1, s3;
  queue<Student> q2, q4;
  
  while(it != students.end()) {
    if(it->kurs == 1) {
      s1.push(*it);
    } else if(it->kurs == 2) {
      q2.push(*it);
    } else if(it->kurs == 3) {
      s3.push(*it);
    } else {
      q4.push(*it);
    }
    it++;
  }

  while(!s1.empty()) {
    cout << s1.top();
    s1.pop();
  }
  cout << endl;

  while(!q2.empty()) {
    cout << q2.front();
    q2.pop();
    
  }
  cout << endl;

  while(!s3.empty()) {
    cout << s3.top();
    s3.pop();
  }
  cout << endl;

  while(!q4.empty()) {
    cout << q4.front();
    q4.pop();
    
  }
}

// 3.2
bool isSortedPalindrome(list<int> &l) {
  if(l.empty()) {
    return true;
  }
  auto start = l.begin();
  auto end = l.end();
  end--;
  bool res = true;
  while(res) {
    res = res && (*start == *end);
    int temp = *start;
    start++;
    if(start != end)
    {
      res = res && (temp <= *start);
      end--;
    }
    else break; 
  }
  return res;

}

// 5.3
void sum(const list<list<int>> &l1, const list<list<int>> &l2) {
  auto row1 = l1.begin(), row2 = l2.begin();
  list<list<int>> result;
  while(row1 != l1.end()) {
    list<int> col;
    auto col1 = row1->begin();
    auto col2 = row2->begin();
    while(col1 != row1->end()) {
      int a = *col1;
      int b = *col2;
      col.push_back(a + b);
      col1++;
      col2++;
    }
    result.push_back(col);
    row1++;
    row2++;
  }

  auto it1 = result.begin();
  while(it1 != result.end()) {
    auto it2 = it1->begin();
    while(it2 != it1->end()) {
      cout << *it2 << " ";
      ++it2;
    }
    ++it1;
    cout << endl;
  }
}

int main() {
  list<int> l;
  l.push_back(1);
  l.push_back(3);
  l.push_back(5);
  l.push_back(7);
  l.push_back(7);
  l.push_back(5);
  l.push_back(3);
  l.push_back(1);
  //cout << isSortedPalindrome(l);
  // queue<string> q;
  // q.push("alabala");
  // q.push("banana");
  // q.push("car");
  // q.push("a");
  // cout << areWordsSorted(q) << endl;

  // list<Student> studs;
  // studs.push_back({"go6o", 1, 1});
  // studs.push_back({"teofil", 1, 2});
  // studs.push_back({"pe6o", 1, 3});
  // studs.push_back({"neofit", 1, 4});
  // studs.push_back({"skeleta", 1, 1});
  // studs.push_back({"stadion", 1, 2});
  // studs.push_back({"minko", 1, 1});
  // studs.push_back({"go6o1", 1, 3});
  // studs.push_back({"go6o2", 1, 4});
  // studs1(studs);
  list<list<int>> first, second;
  first.push_back({4, 5, 5});
  first.push_back({1, 0, 2});
  second.push_back({6, 1, 3});
  second.push_back({1,3,5});
  sum(first, second);

}