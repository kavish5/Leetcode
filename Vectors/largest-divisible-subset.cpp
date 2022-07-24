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
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) {
      return nums;
    }
    sort(nums.begin(), nums.end());
    vector<int> nextIndex(n, -1);
    vector<int> sizes(n, 1);
    int maxLen = 1;
    int maxIndex = 0;
    for (int i = n - 1; i >= 0; i--) {
      int j = i + 1;
      int max = 0;
      int maxIndex = i;
      while (j < n) {
        if (nums[j] % nums[i] == 0 && sizes[j] > max) {
          max = sizes[j];
          maxIndex = j;
        }
        j++;
      }
      if (maxIndex != i) {
        sizes[i] += sizes[maxIndex];
        nextIndex[i] = maxIndex;
        if (max + 1 > maxLen) {
          maxLen = max + 1;
          maxIndex = i;
        }
      }
    }
    vector<int> result;
    int cur = maxIndex;
    while (cur >= 0) {
      result.push_back(nums[cur]);
      cur = nextIndex[cur];
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {3, 4, 16, 8};
  cout << sol.largestDivisibleSubset(nums) << endl;
  return 0;
}