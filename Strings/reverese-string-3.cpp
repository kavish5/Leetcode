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
  string reverseWords(string s) {
    int l = 0;
    int r = 0;
    int size = s.size();
    while (l < size) {
      while (r < size && s[r] != ' ') {
        r++;
      }
      reverse(s.begin() + l, s.begin() + r);
      r = r + 1;
      l = r;
    }
    return s;
  }
};

int main() {
  Solution sol;
  string S = "Let's do coding";
  cout << sol.reverseWords(S) << endl;
  return 0;
}