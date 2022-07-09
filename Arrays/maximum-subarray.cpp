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
  int maxSubArray(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) {
      return 0;
    }
    int maxSoFar = nums[0];
    int curMax = nums[0];
    for (int i = 1; i < size; i++) {
      int n = nums[i];
      curMax = max(curMax + n, n);
      maxSoFar = max(curMax, maxSoFar);
    }
    return maxSoFar;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << sol.maxSubArray(nums) << endl;
  return 0;
}