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
  int majorityElement(vector<int>& nums) {
    int ansIndex = 0;
    int count = 1;
    int size = nums.size();
    for (int i = 1; i < size; i++) {
      if (nums[i] == nums[ansIndex]) {
        count++;
      } else {
        count--;
      }
      if (count == 0) {
        ansIndex = i;
        count = 1;
      }
    }
    int res = nums[ansIndex];
    count = 0;
    for (int j = 0; j < nums.size(); j++) {
      if (nums[j] == res) {
        count++;
      }
    }
    if (count > nums.size() / 2) {
      return nums[ansIndex];
    }
    return 0;
  }
};

int main() {
  Solution sol;
  vector<int> prices = {3, 2, 3};
  cout << sol.majorityElement(prices) << endl;
  return 0;
}