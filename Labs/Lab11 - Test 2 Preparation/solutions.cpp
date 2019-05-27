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

// 5.2
void merge(list<int>& l1, list<int>& l2)
{
  list<int> res; // с една връзка
  l2.push_front(0);
  auto it1 = l1.begin();
  auto it2 = --l2.end();

  while(it1 != l1.end() && it2 != l2.begin())
  {
    if(*it1 == *it2)
    {
      res.push_back(*it1);
      it1++;
      it2--;
    }
    else if(*it1 < *it2)
    {
      res.push_back(*it1);
      it1++;
    }
    else 
    {
      res.push_back(*it2);
      it2--;
    }
  }

  while(it1 != l1.end())
  {
    res.push_back(*it1);
    it1++;
  }
  while(it2 != l2.begin())
  {
    res.push_back(*it2);
    it2--;
  }

  l2.pop_front();

  for(auto it = res.begin(); it != res.end(); ++it)
  {
    cout << *it << " ";
  }
  cout << endl;
}

// 4.3
bool equalK(list<list<int>> &matrix, int k) 
{
  auto it1 = matrix.begin();
  int cnt = 1;
  while (cnt < k) 
  {
    it1++;
    cnt++;
  }
  auto itRow = it1->begin();

  auto it2 = matrix.begin();
  while(it2 != matrix.end()) 
  {
    auto itCol = it2->begin();
    cnt = 1;
    while(cnt < k) 
    {
      itCol++;
      cnt++;
    }
    if(*itRow != *itCol) 
    {
      return false;
    }
    it2++;
    itRow++;
  }

  return true;
}

// 3.3
list<int> listQueueFilter(list<queue<int>> &l) 
{
  list<int> sumL;
  auto it = l.begin();
  while (it != l.end()) 
  {
    queue<int> &curQueue = *it;
    int size = curQueue.size();
    int sum = 0;
    for(int i = 0; i < size; i++) 
    {
      int front = curQueue.front();
      curQueue.pop();
      if (front >= 0) 
      {
        curQueue.push(front);
        sum += front;
      }
    }
    ++it;
    sumL.push_back(sum);
    cout << sum << " ";
  }
  cout << endl;
  return sumL;
}

// 1.3
list<int> intersection(list<list<int>> l) {
  auto it = l.begin();
  list<int> res = *it;
  it++;
  while(it != l.end()) 
  {

    auto itRes = res.begin();

    while(itRes != res.end()) {

      auto itCur = it->begin();
      bool find = false;

      while(!find && itCur != it->end()) {
         if(*itCur == *itRes) {
           find = true;
         }
         itCur++;
      }

      if(!find ) {
        itRes = res.erase(itRes);
      } else  {
        itRes++;
      }
    }

    it++;
  }

  return res;
}

int main() {
  list<list<int>> matrix;
  list<int> row1;
  row1.push_back(1);
  row1.push_back(3);
  row1.push_back(5);
  row1.push_back(7);
  list<int> row2;
  row2.push_back(2);
  row2.push_back(4);
  row2.push_back(5);
  row2.push_back(7);
  list<int> row3;
  row3.push_back(9);
  row3.push_back(3);
  row3.push_back(1);
  row3.push_back(7);
  row3.push_back(5);
  matrix.push_back(row1);
  matrix.push_back(row2);
  matrix.push_back(row3);
  auto res = intersection(matrix);
  for(auto it = res.begin(); it != res.end(); ++it)
  {
    cout << *it <<" ";
  }
  cout << endl;
  // list<int> l, l2;
  // l.push_back(1);
  // l.push_back(3);
  // l.push_back(5);
  // l.push_back(7);
  // l2.push_back(8);
  // l2.push_back(5);
  // l2.push_back(3);
  // merge(l, l2);
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
  // list<list<int>> first, second;
  // first.push_back({4, 5, 5});
  // first.push_back({1, 0, 2});
  // second.push_back({6, 1, 3});
  // second.push_back({1,3,5});
  // sum(first, second);

}