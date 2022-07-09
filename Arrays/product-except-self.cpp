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
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);
    for (int i = 1; i < n; i++) {
      result[i] = result[i - 1] * nums[i - 1];
    }
    int rightProduct = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      result[i] *= rightProduct;
      rightProduct *= nums[i];
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 2, 3, 4};
  cout << sol.productExceptSelf(nums) << endl;
  return 0;
}