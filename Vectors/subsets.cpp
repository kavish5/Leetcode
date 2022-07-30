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
  // vector<vector<int>> subsets(vector<int>& nums) {
  //   if (nums.empty()) {
  //     return {{}};
  //   }
  //   vector<vector<int>> result;
  //   subsetsRec(nums, 0, result);
  //   return result;
  // }

  // void subsetsRec(vector<int>& nums, int index, vector<vector<int>>& result)
  // {
  //   if (index == nums.size() - 1) {
  //     result.push_back({});
  //     result.push_back({nums[index]});
  //   } else {
  //     subsetsRec(nums, index + 1, result);
  //     int n = result.size();
  //     for (int i = 0; i < n; i++) {
  //       vector<int> r = result[i];
  //       r.push_back({nums[index]});
  //       result.push_back(r);
  //     }
  //   }
  // }

  vector<vector<int>> subsets(vector<int>& nums) {
    if (nums.empty()) {
      return {{}};
    }
    for (int x : nums) {
      int n = result.size();
      for (int i = 0; i < n; i++) {
        vector<int> r = result[i];
        r.push_back({nums[index]});
        result.push_back(r);
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 2, 3};
  cout << sol.subsets(nums) << endl;
  return 0;
}