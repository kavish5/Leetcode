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
  int findMaxLength(vector<int>& nums) {
    int size = nums.size();
    if (size < 2) {
      return 0;
    }
    unordered_map<int, int> cache;
    int count = nums[0] == 1 ? 1 : -1;
    cache[0] = -1;
    cache[count] = 0;
    int result = 0;
    for (int i = 1; i < size; i++) {
      count = nums[i] == 1 ? count + 1 : count - 1;
      if (cache.find(count) != cache.end()) {
        result = max(result, i - cache[count]);
      } else {
        cache[count] = i;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {0, 1, 0, 0, 0, 0, 1, 0, 1};
  cout << sol.findMaxLength(nums) << endl;
  return 0;
}