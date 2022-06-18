/*
Approach 1 is to iterate through string and increment counter on every occurence
of character 1.
Approach 2 could be to to AND number with 1 and then add to result. Ensure to
left shift every time the number. This would give us the number of 1s in the
number.
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
  int hammingWeight(uint32_t n) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
      res += (n & 1);
      n >>= 1;
    }
    return res;
  }
};

int main() {
  Solution s;
  // Might give warning
  uint32_t digits = 00000010100101000001111010011100;
  cout << s.hammingWeight(digits) << endl;
  return 0;
}