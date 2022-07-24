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
  int singleNonDuplicate(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (mid % 2 == 0) {
        if (nums[mid] == nums[mid + 1]) {
          left = mid + 2;
        } else if (nums[mid] == nums[mid - 1]) {
          right = mid - 2;
        } else {
          return nums[mid];
        }
      } else {
        if (nums[mid] == nums[mid - 1]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }
    return nums[left];
  }
};

int main() {
  Solution sol;
  vector<int> input = {3, 3, 7, 7, 10, 11, 11};
  cout << sol.singleNonDuplicate(input) << endl;
  return 0;
}