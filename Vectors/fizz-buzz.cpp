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
  vector<string> fizzBuzz(int n) {
    vector<string> result;
    for (int i = 1; i <= n; i++) {
      if (i % 15 == 0) {
        result.push_back("FizzBuzz");
      } else if (i % 3 == 0) {
        result.push_back("Fizz");
      } else if (i % 5 == 0) {
        result.push_back("Buzz");
      } else {
        result.push_back(to_string(i));
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  int n = 19;
  cout << sol.fizzBuzz(n) << endl;
  return 0;
}