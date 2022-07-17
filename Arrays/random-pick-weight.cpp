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
  vector<int> weightSum;
  int sum = 0;

 public:
  Solution(vector<int>& w) {
    sum = 0;
    for (int i : w) {
      sum += i;
      weightSum.push_back(sum);
    }
  }

  int pickIndex() {
    int idx = rand() % sum;
    return binarySearch(idx + 1);
  }

  int binarySearch(int val) {
    int l = 0;
    int r = weightSum.size() - 1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (weightSum[mid] < val) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l;
  }
};

int main() {
  vector<int> w = {7, 1, 5, 3, 6, 4};
  Solution* obj = new Solution(w);
  return 0;
}