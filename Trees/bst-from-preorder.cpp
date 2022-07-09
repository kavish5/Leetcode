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
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    return buildTree(preorder, 0, preorder.size() - 1);
  }

  TreeNode* buildTree(vector<int>& preorder, int l, int r) {
    if (l > r) {
      return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[l]);
    if (l == r) {
      return root;
    }
    int index = l + 1;
    while (index <= r && preorder[index] < preorder[l]) {
      index++;
    }
    root->left = buildTree(preorder, l + 1, index - 1);
    root->right = buildTree(preorder, index, r);
    return root;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {8, 5, 1, 7, 10, 12};
  cout << sol.bstFromPreorder(nums) << endl;
  return 0;
}