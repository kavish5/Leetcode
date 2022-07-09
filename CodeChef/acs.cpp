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
  int countAc(int n) {
    int remainder = n % 100;
    int quotient = n / 100;
    if (quotient + remainder > 10) {
      return -1;
    }
    return quotient + remainder;
  }
};

int main() {
  Solution sol;
  int test;
  cin >> test;
  while (test--) {
    int num;
    cin >> num;
    cout << sol.countAc(num) << endl;
  }
  return 0;
}