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
  bool isCousins(TreeNode* root, int x, int y) {
    int px = 0, py = 0;
    int dx = -1, dy = -1;
    parentDepth(root, x, y, 0, dx, dy, px, py);
    return dx == dy && px != py;
  }

  void parentDepth(TreeNode* root, int x, int y, int d, int& dx, int& dy,
                   int& px, int& py) {
    if (!root) {
      return;
    }
    if (root->left) {
      if (root->left->val == x) {
        px = root->val;
        dx = d + 1;
      } else if (root->left->val == y) {
        py = root->val;
        dy = d + 1;
      }
    }
    if (root->right) {
      if (root->right->val == x) {
        px = root->val;
        dx = d + 1;
      } else if (root->right->val == y) {
        py = root->val;
        dy = d + 1;
      }
    }
    if (dx != -1 && dy != -1) {
      return;
    }
    parentDepth(root->left, x, y, d + 1, dx, dy, px, py);
    parentDepth(root->right, x, y, d + 1, dx, dy, px, py);
  }
};

int main() {
  Solution sol;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode();
  root->left->right = new TreeNode(4);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode();
  root->right->right = new TreeNode(5);
  int x = 5, y = 4;
  cout << sol.isCousins(root, x, y) << endl;
  return 0;
}