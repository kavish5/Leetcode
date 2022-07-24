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
  string getPermutation(int n, int k) {
    vector<int> fact(n, 1);
    vector<int> digit(n, 1);
    for (int i = 1; i < n; i++) {
      fact[i] = fact[i - 1] * (i + 1);
      digit[i] = i + 1;
    }
    string result = "";
    while (result.size() < n - 1) {
      int repeat = fact[fact.size() - 2];
      int nextDigit = (k - 1) / repeat;
      result += to_string(digit[nextDigit]);
      digit.erase(digit.begin() + nextDigit);
      fact.pop_back();
      k = k % repeat;
      if (k == 0) {
        for (int i = digit.size() - 1; i >= 0; i--) {
          result += to_string(digit[i]);
        }
      }
    }
    if (result.size() < n) {
      result += to_string(digit[0]);
    }
    return result;
  }
};

int main() {
  Solution sol;
  int n = 3, k = 2;
  cout << sol.getPermutation(n, k) << endl;
  return 0;
}