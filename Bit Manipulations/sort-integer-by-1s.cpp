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
  // Sort the arr by 1s in binary representation of each number.
  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [](int a, int b) {
      std::bitset<32> bits_a(a);
      std::bitset<32> bits_b(b);
      cout << bits_a.count() << " " << a << endl;
      cout << bits_b.count() << " " << b << endl;
      if (bits_a.count() == bits_b.count()) {
        return a < b;
      }
      return bits_a.count() < bits_b.count();
    });
    return arr;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
  cout << sol.sortByBits(arr) << endl;
  return 0;
}