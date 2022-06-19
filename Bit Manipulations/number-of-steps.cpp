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
  int numberOfSteps(int num) {
    int res = 0;
    bool isOdd = false;
    while (num > 0) {
      isOdd = num & 1;
      if (isOdd) {
        res += 1;
        num -= 1;
      }
      if (num > 0) {
        num = num >> 1;
        res += 1;
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  int n = 123;
  cout << sol.numberOfSteps(n) << endl;
  return 0;
}