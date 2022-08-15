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
  bool isBalanced(TreeNode* root) {
    if (!root) {
      return true;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* temp = q.front();
      q.pop();
      int leftHeight = depth(temp->left);
      int rightHeight = depth(temp->right);
      if (abs(leftHeight - rightHeight) > 1) {
        return false;
      }
      if (temp->left) {
        q.push(temp->left);
      }
      if (temp->right) {
        q.push(temp->right);
      }
    }
    return true;
  }

  int depth(TreeNode* root) {
    if (!root) {
      return 0;
    }
    return 1 + max(depth(root->left), depth(root->right));
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
  cout << sol.isBalanced(root) << endl;
  return 0;
}