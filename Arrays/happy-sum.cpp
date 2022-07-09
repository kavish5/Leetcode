/*
Approach 1 is to add element in set and pop out if present.
Approach 2 is to use XOR property which nullify every repeating numeric
element
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
  bool isHappy(int n) {
    if (n <= 0) {
      return false;
    }
    int slow = n;
    int fast = squareSum(n);
    if (slow == 1 || fast == 1) {
      return true;
    }
    while (slow != fast) {
      slow = squareSum(slow);
      fast = squareSum(squareSum(fast));
      if (slow == 1 || fast == 1) {
        return true;
      }
    }
    return false;
  }

  int squareSum(int n) {
    int sum = 0;
    while (n > 0) {
      int digit = n % 10;
      sum += digit * digit;
      n /= 10;
    }
    return sum;
  }
};

int main() {
  Solution s;
  int num = 19;
  cout << s.isHappy(num) << endl;
  return 0;
}