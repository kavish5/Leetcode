#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

template <typename S>
ostream& operator<<(ostream& os, const vector<S>& vector) {
  for (auto element : vector) {
    os << element << " ";
  }
  return os;
}

struct Node {
  int val;
  struct Node *left, *right;
};

Node* newNode(int val) {
  Node* temp = new Node;
  temp->val = val;
  temp->left = temp->right = NULL;
  return (temp);
}

class Solution {
 public:
  bool isSymmetric(struct Node* root) { return areMirrors(root, root); }

  bool areMirrors(struct Node* rootA, struct Node* rootB) {
    if (rootA == NULL || rootB == NULL) {
      return rootA == rootB;
    }
    if (rootA && rootB && rootA->val == rootB->val) {
      return areMirrors(rootA->left, rootB->right) &&
             areMirrors(rootA->right, rootB->left);
    }
    return false;
  }
};

int main() {
  Solution sol;
  Node* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(2);
  root->left->left = newNode(3);
  root->left->right = newNode(4);
  root->right->left = newNode(4);
  root->right->right = newNode(3);
  cout << sol.isSymmetric(root) << endl;
  return 0;
}