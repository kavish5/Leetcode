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

// trie, dijkstra, knapsack, mst, a*, red black, np complete, gfg

class Solution {
 public:
  int nthUglyNumber(int n) {
    int ugly[n];
    int count = 1;
    ugly[0] = 1;
    int index2 = 0, index3 = 0, index5 = 0;
    while (count < n) {
      int next2 = ugly[index2] * 2;
      int next3 = ugly[index3] * 3;
      int next5 = ugly[index5] * 5;
      int next = min({next2, next3, next5});
      if (next == next2) {
        index2++;
      }
      if (next == next3) {
        index3++;
      }
      if (next == next5) {
        index5++;
      }
      ugly[count++] = next;
    }
    return ugly[n - 1];
  }
};

int main() {
  Solution sol;
  int num = 19;
  cout << sol.nthUglyNumber(num) << endl;
  return 0;
}