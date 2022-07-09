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
  bool checkValidString(string s) {
    if (s.length() < 1) {
      return true;
    }
    int balance = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ')') {
        balance--;
      } else {
        balance++;
      }
      if (balance < 0) {
        return false;
      }
    }
    if (balance == 0) {
      return true;
    }
    balance = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
      if (s[i] == '(') {
        balance--;
      } else {
        balance++;
      }
      if (balance < 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  string S = "(*)";
  cout << sol.checkValidString(S) << endl;
  return 0;
}