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
  // int firstBadVersion(int n) {
  //   if (n <= 0) {
  //     return 0;
  //   }
  //   return isBad(1, n);
  // }

  // int isBad(int start, int end) {
  //   if (start == end) {
  //     return start;
  //   }
  //   int mid = start + (end - start) / 2;
  //   if (isBadVersion(mid)) {
  //     return isBad(start, mid);
  //   }
  //   return isBad(mid + 1, end);
  // }

  int firstBadVersion(int n) {
    int start = 1, end = n;
    while (start < end) {
      int mid = start + (end - start) / 2;
      if (isBadVersion(mid)) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }
    return start;
  }
};

int main() {
  Solution s;
  int num = 19;
  cout << s.firstBadVersion(num) << endl;
  return 0;
}