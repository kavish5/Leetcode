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
  int findComplement(int num) {
    if (num == 0) return 1;
    int count = log2(num) + 1;
    int mask = pow(2, count) - 1;
    return mask ^ num;
  }
};

int main() {
  Solution sol;
  int n = 5;
  cout << sol.findComplement(n) << endl;
  return 0;
}