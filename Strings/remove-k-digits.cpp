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
  string removeKdigits(string num, int k) {
    if (k >= num.length()) {
      return "0";
    }
    int i = 0;
    while (k > 0) {
      i = i > 0 ? i - 1 : 0;
      while (i < num.length() - 1 && num[i] <= num[i + 1]) {
        i++;
      }
      num.erase(num.begin() + i);
      k--;
    }
    auto nonZero = num.find_first_not_of("0");
    num.erase(0, nonZero);
    if (num.length() == 0) {
      return "0";
    }
    return num;
  }
};

int main() {
  Solution sol;
  string num = "1432219";
  int k = 3;
  cout << sol.removeKdigits(num, k) << endl;
  return 0;
}