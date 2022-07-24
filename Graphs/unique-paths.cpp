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
  int uniquePaths(int m, int n) {
    vector<vector<int>> paths(n, vector<int>(m));
    for (int c = 0; c < m; c++) {
      paths[n - 1][c] = 1;
    }
    for (int r = 0; r < n; r++) {
      paths[r][m - 1] = 1;
    }
    for (int r = n - 2; r >= 0; r--) {
      for (int c = m - 2; c >= 0; c--) {
        paths[r][c] = paths[r + 1][c] + paths[r][c + 1];
      }
    }
    return paths[0][0];
  }
};

int main() {
  Solution sol;
  int r = 3, c = 7;
  cout << sol.uniquePaths(c, r) << endl;
  return 0;
}