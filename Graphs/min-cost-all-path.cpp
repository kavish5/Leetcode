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
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size(), res = 0, i = 0, connected = 1;
    vector<bool> visited(n);
    priority_queue<pair<int, int>> pQueue;
    while (connected < n) {
      visited[i] = true;
      for (int j = 0; j < n; j++) {
        if (!visited[j]) {
          pQueue.push({-(abs(points[i][0] - points[j][0]) +
                         abs(points[i][1] - points[j][1])),
                       j});
        }
      }
      while (visited[pQueue.top().second]) {
        pQueue.pop();
      }
      res -= pQueue.top().first;
      i = pQueue.top().second;
      pQueue.pop();
      connected++;
    }
    return res;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
  cout << sol.minCostConnectPoints(points) << endl;
  return 0;
}