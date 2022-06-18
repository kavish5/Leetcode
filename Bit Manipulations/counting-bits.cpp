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
  vector<int> countBits(int n) {
    vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      res[i] = res[i >> 1] + (i & 1);
    }
    return res;
  }
};

int main() {
  Solution s;
  int n = 5;
  cout << s.countBits(n) << endl;
  return 0;
}