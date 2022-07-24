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
  int arrangeCoins(int n) {
    // long long k = sqrt(2 * (long long)n);
    // long long sum = k * (k + 1) / 2;
    // if (sum > n) {
    //   return k - 1;
    // }
    // return k;

    long low = 0, high = n, mid, temp;
    while (low <= high) {
      mid = low + (high - low) / 2;
      temp = mid * (mid + 1) / 2;

      if (temp == n) {
        return mid;
      }
      if (temp <= n) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return low - 1;
  }
};

int main() {
  Solution sol;
  int num = 10;
  cout << sol.arrangeCoins(num) << endl;
  return 0;
}