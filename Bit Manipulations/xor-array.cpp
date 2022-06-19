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
  int xorOperation(int n, int start) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
      res ^= start + 2 * i;
    }
    return res;
  }
};

int main() {
  Solution s;
  int num = 4;
  int start = 3;
  cout << s.xorOperation(num, start) << endl;
  return 0;
}