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
  string reverseStr(string s, int k) {
    int l = 0;
    int size = s.size();
    int r = min(l + k, size);
    while (l < size) {
      reverse(s.begin() + l, s.begin() + r);
      l += 2 * k;
      r = min(l + k, size);
    }
    return s;
  }
};

int main() {
  Solution sol;
  string s = "frequency";
  int k = 2;
  cout << sol.reverseStr(s, k) << endl;
  return 0;
}