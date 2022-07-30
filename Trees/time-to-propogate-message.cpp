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
  int numOfMinutes(int n, int headID, vector<int>& manager,
                   vector<int>& informTime) {
    int res = 0;
    for (int i = 0; i < n; ++i) res = max(res, dfs(i, manager, informTime));
    return res;
  }

  int dfs(int i, vector<int>& manager, vector<int>& informTime) {
    if (manager[i] != -1) {
      informTime[i] += dfs(manager[i], manager, informTime);
      manager[i] = -1;
    }
    return informTime[i];
  }
};

int main() {
  Solution sol;
  int n = 6;
  int headId = 2;
  vector<int> manager = {2, 2, -1, 2, 2, 2};
  vector<int> informTime = {0, 0, 1, 0, 0, 0};
  cout << sol.numOfMinutes(n, headId, manager, informTime) << endl;
  return 0;
}