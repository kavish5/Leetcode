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
  bool divideArray(vector<int>& nums) {
    int freq[501] = {0};
    for (auto num : nums) {
      freq[num]++;
    }
    for (int i = 0; i < 501; i++) {
      if (freq[i] % 2 != 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  vector<int> digit = {9,  9,  19, 10, 9,  12, 2,  12, 3,  3,  11, 5,
                       8,  4,  13, 6,  2,  11, 9,  19, 11, 15, 9,  17,
                       15, 12, 5,  14, 12, 16, 18, 16, 10, 3,  8,  9,
                       16, 20, 2,  4,  16, 12, 11, 14, 20, 16, 2,  18,
                       17, 20, 3,  13, 16, 17, 1,  1,  11, 20, 20, 4};
  cout << s.divideArray(digit) << endl;
  return 0;
}