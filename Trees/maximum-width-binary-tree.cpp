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
  int widthOfBinaryTree(TreeNode* root) {
    if (!root) {
      return 0;
    }
    int result = 1;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
      int count = q.size();
      int start = q.front().second;
      int end = q.back().second;
      result = max(result, end - start + 1);
      for (int i = 0; i < count; i++) {
        pair<TreeNode*, int> p = q.front();
        int index = p.second - start;
        q.pop();
        if (p.first->left) {
          q.push({p.first->left, (long long)2 * index + 1});
        }
        if (p.first->right) {
          q.push({p.first->right, (long long)2 * index + 2});
        }
      }
    }
    return result;
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
  cout << sol.widthOfBinaryTree(root) << endl;
  return 0;
}