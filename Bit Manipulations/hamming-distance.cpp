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
  int hammingDistance(int x, int y) {
    int res = 0;
    int temp = x ^ y;
    while (temp) {
      temp = temp & (temp - 1);
      res += 1;
    }
    return res;
  }
};

int main() {
  Solution sol;
  int x = 3;
  int y = 1;
  cout << sol.hammingDistance(x, y) << endl;
  return 0;
}