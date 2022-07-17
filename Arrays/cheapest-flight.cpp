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
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int k) {
    vector<vector<pair<int, int>>> adj(n);
    for (vector<int>& f : flights) {
      adj[f[0]].push_back({f[1], f[2]});
    }
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> Q;
    Q.push({0, src, k + 1});
    while (!Q.empty()) {
      vector<int> top = Q.top();
      Q.pop();
      int d = top[0];
      int u = top[1];
      int e = top[2];
      if (dst == u) return d;
      if (e > 0) {
        for (pair<int, int>& v : adj[u]) {
          Q.push({d + v.second, v.first, e - 1});
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;
  int n = 4;
  vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}};
  int src = 0, dst = 3, k = 1;
  cout << sol.findCheapestPrice(n, flights, src, dst, k) << endl;
  return 0;
}