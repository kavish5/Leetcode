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
  bool backspaceCompare(string S, string T) {
    stack<char> s1, s2;
    for (char c : S) {
      if (c != '#') {
        s1.push(c);
      } else {
        if (!s1.empty()) {
          s1.pop();
        }
      }
    }
    for (char c : T) {
      if (c != '#') {
        s2.push(c);
      } else {
        if (!s2.empty()) {
          s2.pop();
        }
      }
    }
    while (!s1.empty() && !s2.empty()) {
      if (s1.top() == s2.top()) {
        s1.pop();
        s2.pop();
      } else {
        return false;
      }
    }
    if (!s1.empty() || !s2.empty()) {
      return false;
    }
    return true;
  }
};

int main() {
  Solution sol;
  string S = "ab##";
  string T = "c#d#";
  cout << sol.backspaceCompare(S, T) << endl;
  return 0;
}