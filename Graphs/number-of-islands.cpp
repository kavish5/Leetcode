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
  int numIslands(vector<vector<char>>& grid) {
    int h = grid.size();
    int w = grid[0].size();
    if (!h) return 0;
    if (!w) return 0;
    int count = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (grid[i][j] == '1') {
          dfs(grid, i, j, h, w);
          count++;
        }
      }
    }
    return count;
  }

  void dfs(vector<vector<char>>& grid, int x, int y, int h, int w) {
    grid[x][y] = 0;
    if (x + 1 < h && grid[x + 1][y] == '1') {
      dfs(grid, x + 1, y, h, w);
    }
    if (x - 1 >= 0 && grid[x - 1][y] == '1') {
      dfs(grid, x - 1, y, h, w);
    }
    if (y + 1 < w && grid[x][y + 1] == '1') {
      dfs(grid, x, y + 1, h, w);
    }
    if (y - 1 >= 0 && grid[x][y - 1] == '1') {
      dfs(grid, x, y - 1, h, w);
    }
  }
};

int main() {
  Solution sol;
  vector<vector<char>> grid = {{'1', '0', '1', '0'}};
  cout << sol.numIslands(grid) << endl;
  return 0;
}