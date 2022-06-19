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
  std::string toHex(int num) {
    std::string res = "";
    if (num == 0) {
      return "0";
    }
    unsigned int n = num;
    while (n) {
      int digit = n & 15;
      if (digit < 10) {
        res = char('0' + digit) + res;
      } else {
        res = char('a' + digit - 10) + res;
      }
      n >>= 4;
    }
    return res;
  }
};

int main() {
  Solution s;
  int num = 26;
  cout << s.toHex(num) << endl;
  return 0;
}