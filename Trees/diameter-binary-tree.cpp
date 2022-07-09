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
  int diameterOfBinaryTree(TreeNode* root) {
    int h = 0;
    return diameter(root, h);
  }

  int diameter(TreeNode* root, int& h) {
    if (root == NULL) {
      h = 0;
      return 0;
    }
    int h1 = 0, h2 = 0;
    int d1 = diameter(root->left, h1);
    int d2 = diameter(root->right, h2);
    h = max(h1, h2) + 1;
    return max({d1, d2, h1 + h2});
  }
};

int main() {
  Solution sol;
  TreeNode* root = new TreeNode(1);
  cout << sol.diameterOfBinaryTree(root) << endl;
  return 0;
}