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
  int numSquares(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      int minVal = i;
      int j = 1, square = 1;
      while (square <= i) {
        minVal = min(minVal, 1 + dp[i - square]);
        j++;
        square = j * j;
      }
      dp[i] = minVal;
    }
    return dp[n];
  }
};

int main() {
  Solution sol;
  int n = 19;
  cout << sol.numSquares(n) << endl;
  return 0;
}