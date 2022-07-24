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
  int findDuplicate(vector<int>& nums) {
    // int n = nums.size();
    // int slow = 0;
    // int fast = 0;
    // do {
    //   slow = nums[slow];
    //   fast = nums[nums[fast]];
    // } while (slow != fast);
    // slow = 0;
    // while (slow != fast) {
    //   slow = nums[slow];
    //   fast = nums[fast];
    // }
    // return slow;

    int n = nums.size();
    int maxIndex = 0;
    int curMax = 0;
    for (int i = 0; i < n; i++) {
      int id = nums[i] % n;
      nums[id] += n;
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] > curMax) {
        curMax = nums[i];
        maxIndex = i;
      }
      nums[i] %= n;
    }
    return maxIndex;
  }
};

int main() {
  Solution sol;
  vector<int> digits = {1, 2, 2, 4};
  cout << sol.findDuplicate(digits) << endl;
  return 0;
}