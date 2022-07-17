
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
  int findCircleNum(vector<vector<int>>& isConnected) {
    int count = 0;
    for (int i = 0; i < isConnected.size(); i++) {
      if (isConnected[i][i] == 1) {
        count++;
        dfs(isConnected, i);
      }
    }
    return count;
  }

  void dfs(vector<vector<int>>& isConnected, int v) {
    if (isConnected[v][v] == 0) {
      return;
    }
    for (int i = 0; i < isConnected.size(); i++) {
      if (isConnected[v][i] == 1) {
        isConnected[v][i] = 0;
        dfs(isConnected, i);
      }
    }
  }
};

int main() {
  Solution sol;
  vector<vector<int>> matrix = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  cout << sol.findCircleNum(matrix) << endl;
  return 0;
}