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
  vector<int> findErrorNums(vector<int>& nums) {
    int res[2] = {0, 0};
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int index = abs(nums[i]) - 1;
      if (nums[index] < 0) {
        res[0] = index + 1;
      } else {
        nums[index] = -nums[index];
      }
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] > 0) {
        res[1] = i + 1;
      }
    }
    return vector<int>(res, res + 2);
  }
};

int main() {
  Solution sol;
  vector<int> digits = {1, 2, 2, 4};
  cout << sol.findErrorNums(digits) << endl;
  return 0;
}