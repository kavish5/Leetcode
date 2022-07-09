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
  int numDecodings(string s) {
    int size = s.length();
    if (size < 1 || s[0] == '0') {
      return 0;
    }
    if (size == 1) {
      return 1;
    }
    int val1 = 1;
    int val2 = 1;
    for (int i = 1; i < size; i++) {
      int d1 = s[i] - '0';
      int d2 = (s[i - 1] - '0') * 10 + d1;
      int val = 0;
      if (d1 >= 1) {
        val += val2;
      }
      if (d2 > 9 && d2 < 27) {
        val += val1;
      }
      val1 = val2;
      val2 = val;
    }
    return val2;
  }
};

int main() {
  Solution sol;
  string s = "2101";
  cout << sol.numDecodings(s) << endl;
  return 0;
}