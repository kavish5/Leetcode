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
  bool canJump(vector<int>& nums) {
    int size = nums.size() - 1;
    int reach = 0;
    for (int i = 1; i < size; i++) {
      if (nums[i] + i > reach) {
        reach = nums[i] + i;
      }
      if (reach == i) {
        break;
      }
    }
    return reach >= size;
  }
};

int main() {
  Solution sol;
  vector<int> prices = {0, 2, 3};
  cout << sol.canJump(prices) << endl;
  return 0;
}