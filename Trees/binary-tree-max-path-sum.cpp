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
  int maxPathSum(TreeNode* root) {
    int h = INT_MIN;
    return mpSum(root, h);
  }

  int mpSum(TreeNode* root, int& h) {
    if (root == nullptr) {
      return INT_MIN;
    }
    int h1 = INT_MIN;
    int h2 = INT_MIN;
    int d1 = mpSum(root->left, h1);
    int d2 = mpSum(root->right, h2);
    h = max({h1, h2, 0}) + root->val;
    return max({d1, d2, max(h1, 0) + max(h2, 0) + root->val});
  }
};

int main() {
  Solution sol;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  cout << sol.maxPathSum(root) << endl;
  return 0;
}