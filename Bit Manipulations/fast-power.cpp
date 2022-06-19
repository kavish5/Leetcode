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
  int fastPower(int a, int b, int n) {
    long long res = 1;
    while (b > 0) {
      if (b & 1) {
        res = ((res % n) * (a % n)) % n;
      }
      a = ((a % n) * (a % n)) % n;
      b >>= 1;
    }
  }
};

int main() {
  Solution sol;
  int a = 5;
  int b = 3;
  cout << sol.fastPower(a, b, pow(10, 9) + 7) << endl;
  return 0;
}