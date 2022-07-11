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

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class LRUCache {
  int _capacity;
  list<int> keys;
  unordered_map<int, pair<int, list<int>::iterator>> cache;

 public:
  LRUCache(int capacity) { _capacity = capacity; }

  int get(int key) {
    if (cache.find(key) != cache.end()) {
      keys.erase(cache[key].second);
      keys.push_front(key);
      cache[key].second = keys.begin();
      return cache[key].first;
    }
    return -1;
  }

  void put(int key, int value) {
    if (cache.find(key) != cache.end()) {
      keys.erase(cache[key].second);
    } else {
      if (_capacity == cache.size()) {
        cache.erase(keys.back());
        keys.pop_back();
      }
    }
    keys.push_front(key);
    cache[key] = {value, keys.begin()};
  }
};

int main() {
  LRUCache* obj = new LRUCache(capacity);
  int param = obj->get(key);
  obj->put(key, 1);
  return 0;
}