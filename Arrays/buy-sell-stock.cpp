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
  int maxProfit(vector<int>& prices) {
    int minSoFar = 100000;
    int maxProfit = 0;
    for (auto price : prices) {
      if (minSoFar >= price) {
        minSoFar = price;
      }
      if (maxProfit < price - minSoFar) {
        maxProfit = price - minSoFar;
      }
    }
    return maxProfit;
  }
};

int main() {
  Solution sol;
  vector<int> prices = {7, 6, 4, 3, 1};
  cout << sol.maxProfit(prices) << endl;
  return 0;
}