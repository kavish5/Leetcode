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
  int countElements(vector<int>& nums) {
    unordered_map<int, int> map;
    for (int a : nums) {
      if (map.find(a) != map.end()) {
        map[a]++;
      } else {
        map[a] = 1;
      }
    }
    int result = 0;
    for (auto n : map) {
      if (map.find(n.first + 1) != map.end()) {
        result += n.second;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 1, 2, 2, 3};
  cout << sol.countElements(nums) << endl;
  return 0;
}