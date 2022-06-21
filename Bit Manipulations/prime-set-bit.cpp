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
  int countPrimeSetBits(int left, int right) {
    std::vector<int> v = {2, 3, 5, 7, 11, 13, 17, 19};
    int res = 0;
    while (left <= right) {
      std::bitset<32> bits_n(left);
      int count = bits_n.count();
      res += std::count(v.begin(), v.end(), count);
      left++;
    }
    return res;
  }
};

int main() {
  Solution sol;
  int left = 10;
  int right = 15;
  cout << sol.countPrimeSetBits(left, right) << endl;
  return 0;
}