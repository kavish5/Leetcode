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
  bool isUgly(int n) {
    if (n == 1) return true;
    while (n) {
      if (n == 1) return true;
      if (!(n % 2))
        n /= 2;
      else if (!(n % 3))
        n /= 3;
      else if (!(n % 5))
        n /= 5;
      else
        break;
    }

    return false;
  }

  // bool isUgly(int num) {
  //   if (n > 0)
  //     for (int i = 2; i < 6; i++)
  //       while (n % i == 0) n /= i;
  //   return n == 1;
  // }
};

int main() {
  Solution sol;
  int num = 19;
  cout << sol.isUgly(num) << endl;
  return 0;
}