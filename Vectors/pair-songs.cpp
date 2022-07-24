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
  int numPairsDivisibleBy60(vector<int>& time) {
    vector<int> count(60);
    int result = 0;
    for (int t : time) {
      result += count[(600 - t) % 60];
      count[t % 60] += 1;
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> time = {};
  cout << sol.numPairsDivisibleBy60(time) << endl;
  return 0;
}