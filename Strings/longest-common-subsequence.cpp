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
  int maximalSquare(vector<vector<char>>& matrix) {
    int r = matrix.size();
    if (r == 0) {
      return 0;
    }
    int c = matrix[0].size();
    if (c == 0) {
      return 0;
    }
    int maxSize = 0;
    vector<int> sol(c, 0);
    int diag = matrix[0][0] == '0' ? 0 : 1;

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        int temp = sol[j];
        if (i == 0 || j == 0) {
          if (matrix[i][j] == '1') {
            sol[j] = 1;
            maxSize = max(maxSize, sol[j]);
          } else {
            sol[j] = 0;
          }
        } else {
          if (matrix[i][j] == '1') {
            sol[j] = 1 + min({sol[j], sol[j - 1], diag});
            maxSize = max(maxSize, sol[j]);
          } else {
            sol[j] = 0;
          }
        }
        diag = j == c - 1 ? sol[0] : temp;
      }
    }
    return maxSize * maxSize;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                 {'1', '0', '1', '1', '1'},
                                 {'1', '1', '1', '1', '1'},
                                 {'1', '0', '0', '1', '0'}};
  cout << sol.maximalSquare(matrix) << endl;
  return 0;
}