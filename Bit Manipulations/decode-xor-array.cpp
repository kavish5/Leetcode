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
  vector<int> decode(vector<int>& encoded, int first) {
    vector<int> res{first};
    for (auto val : encoded) res.push_back(first ^= val);
    return res;
  }
};

int main() {
  Solution s;
  vector<int> encoded = {1, 2, 3};
  int first = 1;
  cout << s.decode(encoded, first) << endl;
  return 0;
}