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
  int numJewelsInStones(string jewels, string stones) {
    unordered_set<int> J;
    int count = 0;
    for (char jewel : jewels) {
      J.insert(jewel);
    }
    for (char stone : stones) {
      if (J.find(stone) != J.end()) {
        count++;
      }
    }
    return count;
  }
};

int main() {
  Solution sol;
  string J = "aA";
  string S = "aAAbbbb##";
  cout << sol.numJewelsInStones(J, S) << endl;
  return 0;
