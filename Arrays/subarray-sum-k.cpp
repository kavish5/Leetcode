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
  int subarraySum(vector<int>& nums, int k) {
    int size = nums.size();
    if (size == 0) {
      return 0;
    }
    int count = 0;
    unordered_map<int, int> map;
    int curSum = 0;
    for (int i = 0; i < size; i++) {
      curSum += nums[i];
      if (curSum == k) {
        count++;
      }
      if (map.find(curSum - k) != map.end()) {
        count += map[curSum - k];
      }
      if (map.find(curSum) != map.end()) {
        map[curSum] += 1;
      } else {
        map[curSum] = 1;
      }
    }
    return count;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 0, 1, 2, -1};
  int k = 1;
  cout << sol.subarraySum(nums, k) << endl;
  return 0;
}