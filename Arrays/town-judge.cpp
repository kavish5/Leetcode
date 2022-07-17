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
  int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> trustCount(n, 0);
    for (vector<int> t : trust) {
      trustCount[t[0] - 1]--;
      trustCount[t[1] - 1]++;
    }
    for (int i = 0; i < n; i++) {
      if (trustCount[i] == n - 1) {
        return i + 1;
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> trust = {{1, 3}, {2, 3}};
  int n = 3;
  cout << sol.findJudge(n, trust) << endl;
  return 0;
}