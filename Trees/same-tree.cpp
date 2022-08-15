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

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isSameTree(TreeNode* base, TreeNode* sub) {
    if (!base && !sub) {
      return true;
    }
    if (!base || !sub || base->val != sub->val) {
      return false;
    }
    return isSameTree(base->left, sub->left) &&
           isSameTree(base->right, sub->right);
  }
};

int main() {
  Solution sol;
  TreeNode* rootA = new TreeNode(5);
  rootA->left = new TreeNode(2);
  rootA->left->left = new TreeNode(1);
  rootA->left->right = new TreeNode(4);
  rootA->right = new TreeNode(8);
  rootA->right->left = new TreeNode(6);
  rootA->right->right = new TreeNode(9);

  TreeNode* rootB = new TreeNode(5);
  rootB->left = new TreeNode(1);
  rootB->left->left = new TreeNode(2);
  rootB->left->right = new TreeNode(8);
  rootB->right = new TreeNode(4);
  rootB->right->left = new TreeNode(9);
  rootB->right->right = new TreeNode(6);
  cout << sol.isSameTree(rootA, rootB) << endl;
  return 0;
}