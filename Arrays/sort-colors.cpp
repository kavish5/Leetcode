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
  void sortColors(vector<int>& nums) {
    int p = 0, p0 = 0, p2 = nums.size() - 1;
    while (p <= p2) {
      if (nums[p] == 0) {
        swap(nums[p++], nums[p0++]);
      } else if (nums[p] == 2) {
        swap(nums[p], nums[p2--]);
      } else {
        p++;
      }
    }
  }
};

int main() {
  Solution sol;
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  sol.sortColors(nums);
  return 0;
}