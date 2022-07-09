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
  int strng(vector<int> data, int n) {
    vector<int> prefix(n);
    prefix[0] = data[0];
    for (int i = 1; i < n; i++) {
      prefix[i] = __gcd(prefix[i - 1], data[i]);
    }
    vector<int> suffix(n);
    suffix[n - 1] = data[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      suffix[i] = __gcd(suffix[i + 1], data[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (outsideGcdRange(i, i, prefix, suffix, n) > 1) {
        ans++;
      }
    }
    return ans;
  }

  int outsideGcdRange(int l, int r, vector<int> prefix, vector<int> suffix,
                      int n) {
    if (l == 0) {
      return suffix[r + 1];
    }
    if (r == n - 1) {
      return prefix[l - 1];
    }
    return __gcd(prefix[l - 1], suffix[r + 1]);
  }
};

int main() {
  Solution sol;
  int test;
  cin >> test;
  while (test--) {
    int n, value;
  std:
    vector<int> data;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> value;
      data.push_back(value);
    }
    cout << sol.strng(data, n) << endl;
  }
  return 0;
}