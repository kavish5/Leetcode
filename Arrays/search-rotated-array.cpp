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
  int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid = high / 2;
    while (low <= high) {
      mid = (low + high) / 2;
      if (nums[mid] == target) {
        return mid;
      }
      if (nums[low] <= nums[mid]) {
        if (target >= nums[low] && target < nums[mid]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      } else {
        if (target > nums[mid] && target <= nums[high]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {3, 1};
  int target = 1;
  cout << sol.search(nums, target) << endl;
  return 0;
}