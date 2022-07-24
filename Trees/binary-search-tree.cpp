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
  TreeNode* searchBST(TreeNode* root, int val) {
    // if (root == NULL) {
    //   return nullptr;
    // }
    // if (root->val == val) {
    //   return root;
    // } else {
    //   if (root->val > val) {
    //     return searchBST(root->left, val);
    //   } else {
    //     return searchBST(root->right, val);
    //   }
    // }
    // return nullptr;

    TreeNode* cur = root;
    while (cur) {
      if (cur->val == val) {
        return cur;
      } else if (cur->val > val) {
        cur = cur->left;
      } else {
        cur = cur->right;
      }
    }
    return cur;
  }
};

int main() {
  Solution sol;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  int val = 3;
  cout << sol.searchBST(root, val) << endl;
  return 0;
}