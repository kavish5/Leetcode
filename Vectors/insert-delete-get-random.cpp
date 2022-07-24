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

class RandomizedSet {
  vector<int> nums;
  unordered_map<int, int> map;

 public:
  RandomizedSet() {}

  bool insert(int val) {
    if (map.find(val) != map.end()) {
      return false;
    }
    nums.push_back(val);
    map.insert({val, nums.size() - 1});
    return true;
  }

  bool remove(int val) {
    if (map.find(val) == map.end()) {
      return false;
    }
  };
  int pos = map[val];
  nums[pos] = nums[nums.size() - 1];
  map[nums[pos]] = pos;
  nums.pop_back();
  map.erase(val);
  return true;
}

  int getRandom() {
  return nums[rand() % nums.size()];
}

int main() {
  RandomizedSet* obj = new RandomizedSet();
  int val = 5;
  bool param_1 = obj->insert(val);
  bool param_2 = obj->remove(val);
  int param_3 = obj->getRandom();
}