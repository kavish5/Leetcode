/*
Approach 1 is to add element in set and pop out if present.
Approach 2 is to use XOR property which nullify every repeating numeric
element
*/
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
  int singleNumber(vector<int>& nums) {
    int res = 0;
    int k = 3;
    int bits[32] = {0};
    for (int i = 0; i < 32; i++) {
      for (int num : nums) {
        bits[i] += num >> i & 1;
        bits[i] %= k;
      }
    }
    for (int i = 0; i < 32; i++) {
      res |= (bits[i] << i);
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> digits = {1, 2, 3, 2, 2, 1, 1};
  cout << s.singleNumber(digits) << endl;
  return 0;
}