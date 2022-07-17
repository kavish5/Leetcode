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
  bool isSubsequence(string s, string t) {
    int size = t.length();
    int j = 0;
    if (s.length() > size) return false;
    for (int i = 0; i < size; i++) {
      if (t[i] == s[j]) {
        j++;
      }
    }
    return j == s.length();
  }
};

int main() {
  Solution sol;
  string word1 = "ahbgdc";
  string word2 = "dcf";
  cout << sol.isSubsequence(word2, word1) << endl;
  return 0;
}