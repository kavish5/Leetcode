/*
Approach 1 is to add element in set and pop out if present.
Approach 2 is to use XOR property which nullify every repeating numeric
element
*/
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
  void moveZeroes(vector<int> nums) {
    int size = nums.size();
    if (size <= 1) {
      return;
    }
    int z = 0, n = 1;
    while (size > n && size > z && n > z) {
      while (size > z && nums[z] != 0) {
        z++;
      }
      if (n < z) {
        n = z + 1;
      }
      while (size > n && nums[n] == 0) {
        n++;
      }
      if (z >= n || n >= size || z >= size) {
        return;
      }
      iter_swap(nums.begin() + z, nums.begin() + n);
    }
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 3, 0, 0, 2, 1};
  s.moveZeroes(nums);
  return 0;
}