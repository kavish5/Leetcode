/*
Approach 1 could be naive approach of mod by 3 followed by divide by 3.
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
  bool isPowerOfN(int num, int n) {
    while (num >= n) {
      if (num % n != 0) {
        return false;
      }
      num /= n;
    }
    return num == 1;
  }
};

int main() {
  Solution s;
  int num = 27;
  int n = 3;
  cout << s.isPowerOfN(num, n) << endl;
  return 0;
}