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
  bool isPerfectSquare(int num) {
    int lastDigit = num % 10;
    if (lastDigit == 2 || lastDigit == 3 || lastDigit == 7 || lastDigit == 8) {
      return false;
    }
    int low = 1, high = num;
    while (low <= high) {
      long long int mid = low + (high - low) / 2;
      long long int square = mid * mid;
      if (square == num) {
        return true;
      } else if (square < num) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;
  int num = 49;
  cout << sol.isPerfectSquare(num) << endl;
  return 0;
}