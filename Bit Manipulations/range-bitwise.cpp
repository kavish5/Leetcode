/*
9 + 1 = 10; carry 1; value changes
Other numbers - just value changes
Ensure carry is not set
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
  int rangeBitwise(int left, int right) {
    int shifts = 0;
    while (left < right) {
      left >>= 1;
      right >>= 1;
      shifts++;
    }
    return right << shifts;
  }
};

int main() {
  Solution s;
  int left = 5;
  int right = 7;
  cout << s.rangeBitwise(left, right) << endl;
  return 0;
}