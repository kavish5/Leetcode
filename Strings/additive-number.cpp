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
  bool isAdditiveNumber(string num) {
    int n = num.length();
    for (int i = 1; i < n - 1; i++) {
      long long val1 = stol(num.substr(0, i));
      if (to_string(val1) != num.substr(0, i)) {
        break;
      }
      for (int j = i + 1; j < n; j++) {
        long long val2 = stol(num.substr(i, j - i));
        if (to_string(val2) != num.substr(i, j - i)) {
          break;
        }
        bool found = findRec(val1, val2, num.substr(j), false);
        if (found) {
          return true;
        }
      }
    }
    return false;
  }

  bool findRec(long long val1, long long val2, string s, bool found) {
    if (s.length() == 0 && found) {
      return found;
    }
    string val3 = to_string(val1 + val2);
    int index = min(s.length(), val3.length());
    if (s.substr(0, index) == val3) {
      return findRec(val2, stol(val3), s.substr(index), true);
    }
    return false;
  }
};

int main() {
  Solution sol;
  string input = "211738";
  cout << sol.isAdditiveNumber(input) << endl;
  return 0;
}