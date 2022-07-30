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
  vector<int> prisonAfterNDays(vector<int>& cells, int n) {
    unordered_map<string, int> map;
    for (int i = 0; i < n; i++) {
      string s(cells.begin(), cells.end());
      if (map.find(s) != map.end()) {
        int loop = i - map[s];
        int remaining = (n - i) % loop;
        return prisonAfterNDays(cells, remaining);
      } else {
        map.insert({s, i});
        int prev = cells[0];
        for (int j = 1; j < 7; j++) {
          int next = cells[j + 1];
          int cur = cells[j];
          cells[j] = prev == next;
          prev = cur;
        }
      }
      cells[0] = 0;
      cells[7] = 0;
    }
    return cells;
  }
};

int main() {
  Solution sol;
  vector<int> cells = {0, 1, 0, 1, 1, 0, 0, 1};
  int n = 7;
  cout << sol.prisonAfterNDays(cells, n) << endl;
  return 0;
}