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

class MinStack {
  stack<int> s1;
  stack<int> s2;

 public:
  MinStack() {}

  void push(int val) {
    s1.push(val);
    if (!s2.empty()) {
      int top = s2.top();
      if (top < val) {
        s2.push(top);
      } else {
        s2.push(val);
      }
    } else {
      s2.push(val);
    }
  }

  void pop() {
    s1.pop();
    s2.pop();
  }

  int top() { return s1.top(); }

  int getMin() { return s2.top(); }
};