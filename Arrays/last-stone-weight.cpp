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
  int lastStoneWeight(vector<int>& stones) {
    make_heap(stones.begin(), stones.end());
    while (stones.size() > 1) {
      pop_heap(stones.begin(), stones.end());
      int x = stones.back();
      stones.pop_back();

      pop_heap(stones.begin(), stones.end());
      int y = stones.back();
      stones.pop_back();

      int diff = abs(y - x);
      if (diff > 0) {
        stones.push_back(diff);
        push_heap(stones.begin(), stones.end());
      }
    }
    if (stones.size() == 1) {
      return stones[0];
    }
    return 0;
  }
};

int main() {
  Solution sol;
  vector<int> stones = {7, 1, 5, 3, 6, 4, 9};
  cout << sol.lastStoneWeight(stones) << endl;
  return 0;
}