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
  int count = 0;

 public:
  int kthSmallest(TreeNode* root, int k) {
    TreeNode* node = getKthSmallestElement(root, k);
    return node->val;
  }

  TreeNode* getKthSmallestElement(TreeNode* root, int k) {
    if (!root) {
      return NULL;
    }
    TreeNode* left = getKthSmallestElement(root->left, k);
    if (left) {
      return left;
    }
    count++;
    if (count == k) {
      return root;
    }
    return getKthSmallestElement(root->right, k);
  }
};

int main() {
  Solution sol;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->left->left = new TreeNode(2);
  root->left->left->left = new TreeNode(1);
  root->left->right = new TreeNode(4);
  root->right = new TreeNode(8);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(9);
  int k = 4;
  cout << sol.kthSmallest(root, k) << endl;
  return 0;
}