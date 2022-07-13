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
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> map;
    for (char c : magazine) {
      if (map.find(c) != map.end()) {
        int count = map[c] + 1;
        map[c] = count;
      } else {
        map.insert({c, 1});
      }
    }
    for (char c : ransomNote) {
      if (map.find(c) == map.end()) {
        return false;
      }
      int count = map[c];
      if (count == 0) {
        return false;
      }
      map[c] = count - 1;
    }
    return true;
  }
};

int main() {
  Solution sol;
  string ransomNote = "aAc";
  string magazine = "aAAbbbb";
  cout << sol.canConstruct(ransomNote, magazine) << endl;
  return 0;
}