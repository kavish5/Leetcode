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
  bool isValidSequence(TreeNode* root, vector<int>& arr) {
    if (!root) {
      return arr.size() == 0;
    }
    return isValid(root, arr, 0);
  }

  bool isValid(TreeNode* root, vector<int>& arr, int idx) {
    if (root->val != arr[idx]) {
      return false;
    }
    if (idx == arr.size() - 1) {
      return !root->left && !root->right;
    }
    return (root->left && isValid(root->left, arr, idx + 1)) ||
           (root->right && isValid(root->right, arr, idx + 1));
  }
};

int main() {
  Solution sol;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  vector<int> arr = {1, 2};
  cout << sol.isValidSequence(root, arr) << endl;
  return 0;
}