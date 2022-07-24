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
  int countPrimes(int n) {
    int count = 0;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    if (n <= 2) {
      return 0;
    }
    for (int i = 2; i * i <= n; i++) {
      if (prime[i]) {
        for (int j = i * i; j <= n; j += i) {
          prime[j] = false;
        }
      }
    }
    for (int i = 2; i < n; i++) {
      if (prime[i]) {
        count++;
      }
    }
    return count;
  }
};

int main() {
  Solution sol;
  int num = 10;
  cout << sol.countPrimes(num) << endl;
  return 0;
}