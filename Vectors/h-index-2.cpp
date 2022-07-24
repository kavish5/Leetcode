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
  int hIndex(vector<int>& citations) {
    // int n = citations.size();
    // int i = n - 1;
    // while (i >= 0) {
    //   if (citations[i] < n - i) {
    //     break;
    //   }
    //   i--;
    // }
    // return n - i - 1;

    int n = citations.size();
    int l = 0, r = n - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (citations[mid] < n - mid) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return n - l;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 2, 3, 5, 6, 7, 8, 10};
  cout << sol.hIndex(nums) << endl;
  return 0;
}