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
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<vector<int>> result;
    sort(people.begin(), people.end(),
         [](const vector<int>& a, const vector<int>& b) {
           if (a[0] == b[0]) {
             return a[1] < b[1];
           }
           return a[0] > b[0];
         });
    for (vector<int>& x : people) {
      result.insert(result.begin() + x[1], x);
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> coordinates = {{7, 0}, {4, 4}, {7, 1},
                                     {5, 0}, {6, 1}, {5, 2}};
  cout << sol.reconstructQueue(coordinates) << endl;
  return 0;
}