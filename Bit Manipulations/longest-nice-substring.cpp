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
  std::string longestNiceSubstring(std::string s) {
  std:
    string maxString = "";
    for (int i = 0; i < s.size(); i++) {
      for (int j = i; j < s.size(); j++) {
        if (isNice(s, i, j) && (maxString.size() < j - i + 1)) {
          maxString = s.substr(i, j - i + 1);
        }
      }
    }
    return maxString;
  }

  bool isNice(std::string s, int i, int j) {
    int lower[26] = {};
    int upper[26] = {};
    for (int k = i; k <= j; k++) {
      if (islower(s[k])) {
        lower[s[k] - 'a'] = 1;
      } else {
        upper[s[k] - 'A'] = 1;
      }
    }
    for (int k = 0; k < 26; k++) {
      if ((lower[k] > 0 || upper[k] > 0) && lower[k] + upper[k] == 1) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
std:
  string str = "EEXx";
  cout << s.longestNiceSubstring(str) << endl;
  return 0;
}