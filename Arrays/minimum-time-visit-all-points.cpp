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
  int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int result = 0;
    vector<int> p1 = points[0];
    int size = points.size();
    for (int i = 1; i < size; i++) {
      vector<int> p2 = points[i];
      int dx = p2[0] - p1[0];
      int dy = p2[1] - p1[1];
      p1 = p2;
      result += max(abs(dx), abs(dy));
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> coordinates = {{1, 1}, {3, 4}, {-1, 0}};
  cout << sol.minTimeToVisitAllPoints(coordinates) << endl;
  return 0;
}