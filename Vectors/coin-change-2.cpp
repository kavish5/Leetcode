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
  int change(int amount, vector<int>& coins) {
    // int size = coins.size();
    // vector<vector<int>> dp(size + 1, vector<int>(amount + 1, 0));
    // for (int i = 0; i <= size; i++) {
    //   for (int j = 0; j <= amount; j++) {
    //     if (j == 0) {
    //       dp[i][j] = 1;
    //     } else if (i == 0) {
    //       dp[i][j] = 0;
    //     } else {
    //       dp[i][j] = dp[i - 1][j];
    //       if ((j - coins[i - 1]) >= 0) {
    //         dp[i][j] += dp[i][j - coins[i - 1]];
    //       }
    //     }
    //   }
    // }
    // return dp[size][amount];

    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int c : coins) {
      for (int j = c; j <= amount; j++) {
        dp[j] += dp[j - c];
      }
    }
    return dp[amount];
  }
};

int main() {
  Solution sol;
  vector<int> coins = {1, 2, 5};
  int amount = 5;
  cout << sol.change(amount, coins) << endl;
  return 0;
}