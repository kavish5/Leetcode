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
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int r = dungeon.size();
    int c = dungeon[0].size();
    vector<vector<int>> sol(r, vector<int>(c));
    sol[r - 1][c - 1] =
        dungeon[r - 1][c - 1] > 0 ? 1 : 1 - dungeon[r - 1][c - 1];
    for (int i = r - 2; i >= 0; i--) {
      sol[i][c - 1] = max(sol[i + 1][c - 1] - dungeon[i][c - 1], 1);
    }
    for (int j = c - 2; j >= 0; j--) {
      sol[r - 1][j] = max(sol[r - 1][j + 1] - dungeon[r - 1][j], 1);
    }
    for (int i = r - 2; i >= 0; i--) {
      for (int j = c - 2; j >= 0; j--) {
        sol[i][j] = max(min(sol[i + 1][j], sol[i][j + 1]) - dungeon[i][j], 1);
      }
    }
    return sol[0][0];
  }
};

int main() {
  Solution sol;
  vector<vector<int>> dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
  cout << sol.calculateMinimumHP(dungeon) << endl;
  return 0;
}