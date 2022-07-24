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
  int countNodes(TreeNode* root) {
    if (!root) {
      return 0;
    }
    int hLeft = 0, hRight = 0;
    TreeNode* left = root;
    TreeNode* right = root;
    while (left) {
      hLeft++;
      left = left->left;
    }
    while (right) {
      hRight++;
      right = right->right;
    }
    if (hLeft == hRight) {
      return (1 << hLeft) - 1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};

int main() {
  Solution sol;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  cout << sol.countNodes(root) << endl;
  return 0;
}