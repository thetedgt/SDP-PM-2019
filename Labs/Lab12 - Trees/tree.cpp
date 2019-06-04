#include <iostream>
#include <iomanip>
using namespace std;

struct Node
{
  int val;
  Node *l, *r;

  Node(int val = 0, Node* left = nullptr, Node* right = nullptr) : 
    l(left), r(right), val(val)
  {}

  ~Node()
  {
    if(l) delete l;
    if(r) delete r;
  }
};

void printTree(const Node* root, int level = 0)
{
  if(root)
  {
    if(root->l) {
      printTree(root->l, level + 1);
    }
    cout << setw(level * 4) << root->val << endl;
    if(root->r) {
      printTree(root->r, level + 1);
    }
  }
}

Node* buildTree()
{
  char c;
  cin >> c; // (
  if(cin.peek() == ')') {
    cin >> c;
    return nullptr;
  
  }

  int a;
  cin >> a;
  Node *left = buildTree();
  Node *right = buildTree();
  cin >> c; // )

  Node *temp = new Node(a, left, right);
  return temp;
}

int lca(Node *root, int a, int b)
{
  if(root)
  {
    if(a < root->val && b < root->val)
      return lca(root->l, a, b);
    if(a > root->val && b > root->val)
      return lca(root->r, a, b);
    return root->val;
  }
  return -1;
}

int maxSumPathToLeaf(Node* root)
{
  if(!root) return INT_LEAST32_MIN; // to assure that we visit the leaves
  return max(maxSumPathToLeaf(root->l), maxSumPathToLeaf(root->r)) 
            + root->val;
}

int main() {
  Node *root = new Node(105, nullptr, new Node(205, new Node(200), new Node(208, new Node(206))));
  printTree(root);
  cout << lca(root, 208, 206) << endl;
  return 0;
}

// (5 (6 () (7 () ())) (1 (2 () ()) ()))