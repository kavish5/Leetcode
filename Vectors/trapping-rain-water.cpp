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
  int trap(vector<int>& height) {
    int n = height.size();
    int* left = new int[n];
    int* right = new int[n];
    left[0] = height[0];
    for (int i = 1; i < n; i++) {
      left[i] = max(left[i - 1], height[i]);
    }
    right[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      right[i] = max(right[i + 1], height[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += min(left[i], right[i]) - height[i];
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << sol.trap(height) << endl;
  return 0;
}