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
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    float slope = getSlope(coordinates[0], coordinates[1]);
    int size = coordinates.size();
    for (int i = 2; i < size; i++) {
      float m = getSlope(coordinates[0], coordinates[i]);
      if (m != slope) {
        return false;
      }
    }
    return true;
  }

  float getSlope(vector<int> p1, vector<int> p2) {
    if (p1[0] == p2[0]) {
      return 100000;
    }
    return (float)(p2[1] - p1[1]) / (p2[0] - p1[0]);
  }
};

int main() {
  Solution sol;
  vector<vector<int>> coordinates = {{1, 1}, {2, 2}, {3, 4},
                                     {4, 5}, {5, 6}, {7, 7}};
  cout << sol.checkStraightLine(coordinates) << endl;
  return 0;
}