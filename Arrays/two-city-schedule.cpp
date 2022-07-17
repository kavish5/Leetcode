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
  int twoCitySchedCost(vector<vector<int>>& costs) {
    sort(costs.begin(), costs.end(),
         [](const vector<int>& a, const vector<int>& b) {
           return (a[0] - a[1]) < (b[0] - b[1]);
         });
    int cost = 0;
    for (int i = 0; i < costs.size() / 2; i++) {
      cost += costs[i][0];
    }
    for (int i = costs.size() / 2; i < costs.size(); i++) {
      cost += costs[i][1];
    }
    return cost;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> input = {{515, 563}, {451, 713}, {537, 709}, {343, 819},
                               {855, 779}, {457, 60},  {650, 359}, {631, 42}};
  cout << sol.twoCitySchedCost(input) << endl;
  return 0;
}