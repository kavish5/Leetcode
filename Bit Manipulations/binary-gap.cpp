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
  int binaryGap(int n) {
    int globalCount = 0;
    int localCount = -32;
    while (n > 0) {
      if (n & 1) {
        globalCount = max(globalCount, localCount);
        localCount = 0;
      }
      localCount++;
      n = n >> 1;
    }
    return globalCount;
  }
};

int main() {
  Solution sol;
  int num = 8;
  cout << sol.binaryGap(num) << endl;
  return 0;
}