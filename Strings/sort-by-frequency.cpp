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
  string frequencySort(string s) {
    unordered_map<char, int> map;
    for (char c : s) {
      if (map.find(c) != map.end()) {
        map[c]++;
      } else {
        map[c] = 1;
      }
    }
    vector<pair<char, int>> countVec(map.begin(), map.end());
    sort(countVec.begin(), countVec.end(),
         [](pair<char, int>& p1, pair<char, int>& p2) {
           return p1.second > p2.second;
         });

    string result = "";
    for (pair<char, int> p : countVec) {
      for (int i = 0; i < p.second; i++) {
        result += p.first;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  string input = "frequency";
  cout << sol.frequencySort(input) << endl;
  return 0;
}