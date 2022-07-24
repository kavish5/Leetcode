/*
Approach 1 is to add element in set and pop out if present.
Approach 2 is to use XOR property which nullify every repeating numeric
element
*/
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
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    if (strs.size() == 0) {
      return result;
    }
    unordered_map<string, vector<string>> map;
    for (string s : strs) {
      string key = s;
    std:
      sort(key.begin(), key.end());
      map[key].push_back(s);
    }
    for (auto it = map.begin(); it != map.end(); it++) {
      result.push_back(it->second);
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<string> strs = {"ate", "eat", "tan", "nat", "tna", "tea"};
  cout << s.groupAnagrams(strs);
  return 0;
}