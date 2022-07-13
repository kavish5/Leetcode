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
  int firstUniqueChar(string s) {
    int count[26] = {};
    for (char c : s) {
      count[c - 'a'] += 1;
    }
    for (int i = 0; i < s.length(); i++) {
      if (count[s[i] - 'a'] == 1) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;
  std::string input = "abcaabd";
  cout << sol.firstUniqueChar(input) << endl;
  return 0;
}