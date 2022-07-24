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
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++) {
      if (umap.find(nums[i]) != umap.end()) {
        return {umap.at(nums[i]), i};
      } else {
        umap.insert({target - nums[i], i});
      }
    }
    return {};
  }
};

int main() {
  Solution sol;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  int target = 9;
  cout << sol.twoSum(nums, target) << endl;
  return 0;
}