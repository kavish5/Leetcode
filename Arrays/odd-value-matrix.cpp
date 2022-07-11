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
  int oddCells(int m, int n, vector<vector<int>>& indices) {
    vector<bool> M(m, false);
    vector<bool> N(n, false);
    int indexSize = indices.size();
    for (int i = 0; i < indexSize; i++) {
      M[indices[i][0]] = M[indices[i][0]] ^ true;
      N[indices[i][1]] = N[indices[i][1]] ^ true;
    }
    int r = 0, c = 0;
    for (int i = 0; i < m; i++) {
      if (M[i]) {
        r++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (N[i]) {
        c++;
      }
    }
    return r * n + c * m - 2 * r * c;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> indices = {{0, 1}, {1, 1}};
  int m = 2, n = 3;
  cout << sol.oddCells(m, n, indices) << endl;
  return 0;
}