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
#include <unordered_set>
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
  string convertToTitle(int columnNumber) {
    // string result = "";
    // while (columnNumber) {
    //   char ch = 'A' + (columnNumber - 1) % 26;
    //   result = ch + result;
    //   columnNumber = (columnNumber - 1) / 26;
    // }
    // return result;

    string result = "";
    while (columnNumber > 0) {
      int digit = columnNumber % 26;
      if (digit == 0) digit = 26;
      columnNumber /= 26;
      if (digit == 26) columnNumber--;
      char c = 'A' + digit - 1;
      result = result + c;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  Solution sol;
  int n = 45;
  cout << sol.convertToTitle(n) << endl;
  return 0;
}