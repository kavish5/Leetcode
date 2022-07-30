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
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int size = nums.size();
    if (size < 3) {
      return result;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < size - 2; i++) {
      if (i == 0 || nums[i] != nums[i - 1]) {
        int left = i + 1;
        int right = size - 1;
        while (left < right) {
          int sum = nums[left] + nums[right] + nums[i];
          if (sum > 0) {
            right--;
          } else if (sum < 0) {
            left++;
          } else {
            result.push_back({nums[i], nums[left], nums[right]});
            while (left < right && nums[left] == nums[left + 1]) {
              left++;
            }
            while (left < right && nums[right] == nums[right - 1]) {
              right--;
            }
            left++;
            right--;
          }
        }
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {-1, 0, 1, 2, -1, 4};
  cout << sol.threeSum(nums) << endl;
  return 0;
}