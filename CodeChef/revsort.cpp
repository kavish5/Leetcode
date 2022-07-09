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
  string revsort(vector<int> data, int n, int x) {
    bool flag = true;
    for (int i = 0; i < n - 1; i++) {
      if (data[i] > data[i + 1]) {
        if ((data[i] + data[i + 1]) <= x) {
          int temp = data[i + 1];
          data[i + 1] = data[i];
          data[i] = temp;
        } else {
          flag = false;
          break;
        }
      }
    }
    return flag ? "YES" : "NO";
  }
};

int main() {
  Solution sol;
  int test;
  cin >> test;
  while (test--) {
    int n, x, value;
  std:
    vector<int> data;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
      cin >> value;
      data.push_back(value);
    }
    cout << sol.revsort(data, n, x) << endl;
  }
  return 0;
}