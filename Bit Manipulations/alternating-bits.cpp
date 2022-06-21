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
  bool hasAlternatingBits(int n) {
    std::bitset<32> bits_n(n);
    for (int i = 0; i < log(n) + 1; i++) {
      if (bits_n[i] == bits_n[i + 1]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  int n = 7;
  cout << sol.hasAlternatingBits(n) << endl;
  return 0;
}