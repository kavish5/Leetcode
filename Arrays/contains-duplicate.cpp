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
  bool containsDuplicate(vector<int>& nums) {
    std::set<int> s;
    if (nums.size() == 0 || nums.size() == 1) {
      return false;
    }
    for (auto num : nums) {
      if (s.count(num)) {
        return true;
      }
      s.insert(num);
    }
    return false;
  }
};

int main() {
  Solution sol;
  vector<int> prices = {7, 1, 5, 3, 6, 4, 4};
  cout << sol.containsDuplicate(prices) << endl;
  return 0;
}