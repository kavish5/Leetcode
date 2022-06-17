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
  vector<int> plusOne(vector<int>& digits) {
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (digits[i] + carry == 10) {
        digits[i] = 0;
      } else {
        digits[i] += carry;
        carry = 0;
        break;
      }
    }
    if (carry == 1) {
      digits.insert(digits.begin(), 1);
    }
    return digits;
  }
};

int main() {
  Solution s;
  vector<int> digits = {1, 2, 3};
  cout << s.plusOne(digits) << endl;
  return 0;
}