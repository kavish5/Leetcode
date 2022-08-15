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
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root && !subRoot) {
      return true;
    }
    if (!root || !subRoot) {
      return false;
    }
    if (areIdenticals(root, subRoot)) {
      return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }

  bool areIdenticals(TreeNode* base, TreeNode* sub) {
    if (!base && !sub) {
      return true;
    }
    if (!base || !sub || base->val != sub->val) {
      return false;
    }
    return areIdenticals(base->left, sub->left) &&
           areIdenticals(base->right, sub->right);
  }
};

int main() {
  Solution sol;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(4);
  root->right = new TreeNode(8);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(9);
  TreeNode* subRoot = new TreeNode(8);
  subRoot->left = new TreeNode(6);
  subRoot->left->left = new TreeNode(9);
  cout << sol.isSubtree(root, subRoot) << endl;
  return 0;
}