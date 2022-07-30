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
  int islandPerimeter(vector<vector<int>>& grid) {
    int h = grid.size();
    if (!h) return 0;
    int w = grid[0].size();
    if (!w) return 0;
    int perimeter = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (grid[i][j] == 1) {
          perimeter += calculatePerimeter(grid, i, j, h, w);
        }
      }
    }
    return perimeter;
  }

  int calculatePerimeter(vector<vector<int>>& grid, int x, int y, int h,
                         int w) {
    int maxPerimeter = 4;
    if (x + 1 < h && grid[x + 1][y] == 1) {
      maxPerimeter--;
    }
    if (x - 1 >= 0 && grid[x - 1][y] == 1) {
      maxPerimeter--;
    }
    if (y + 1 < w && grid[x][y + 1] == 1) {
      maxPerimeter--;
    }
    if (y - 1 >= 0 && grid[x][y - 1] == 1) {
      maxPerimeter--;
    }
    return maxPerimeter;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> grid = {
      {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
  cout << sol.islandPerimeter(grid) << endl;
  return 0;
}