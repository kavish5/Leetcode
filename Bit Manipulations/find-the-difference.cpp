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
  char findTheDifference(std::string s, std::string t) {
    char res = 0;
    if (s.size() > t.size()) {
      return findTheDifference(t, s);
    }
    for (int i = 0; i < s.size(); i++) {
      res ^= s[i] ^ t[i];
    }
    for (int i = s.size(); i < t.size(); i++) {
      res ^= t[i];
    }
    return res;
  }
};

int main() {
  Solution sol;
  std::string s = "";
  std::string t = "y";
  cout << sol.findTheDifference(s, t) << endl;
  return 0;
}