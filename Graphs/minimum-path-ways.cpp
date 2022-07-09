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

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    if (m == 0) return 0;
    int n = grid[0].size();
    if (n == 0) return 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i - 1 >= 0 && j - 1 >= 0) {
          grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        } else {
          if (i - 1 >= 0) {
            grid[i][j] += grid[i - 1][j];
          } else if (j - 1 >= 0) {
            grid[i][j] += grid[i][j - 1];
          }
        }
      }
    }
    return grid[m - 1][n - 1];
  }
};

int main() {
  Solution sol;
  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  cout << sol.minPathSum(grid) << endl;
  return 0;
}