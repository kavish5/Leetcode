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
  int maxArea(vector<int>& height) {
    int width = height.size() - 1;
    int left = 0;
    int right = width;
    int area = width * min(height[left], height[right]);
    while (left < right) {
      if (height[left] <= height[right]) {
        left++;
      } else {
        right--;
      }
      width--;
      area = max(area, width * min(height[left], height[right]));
    }
    return area;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << sol.maxArea(nums) << endl;
  return 0;
}