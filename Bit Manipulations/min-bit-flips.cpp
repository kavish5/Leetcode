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
  int minBitFlips(int start, int goal) {
    int value = start ^ goal;
    int count = 0;
    while (value) {
      value = value & value - 1;
      count++;
    }
    return count;
  }
};

int main() {
  Solution sol;
  int start = 10;
  int goal = 7;
  cout << sol.minBitFlips(start, goal) << endl;
  return 0;
}