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

class MyStack {
 private:
  queue<int> q;

 public:
  MyStack() {}

  void push(int x) {
    q.push(x);
    for (int i = 0; i < q.size() - 1; i++) {
      q.push(q.front());
      q.pop();
    }
  }

  int pop() {
    int x = q.front();
    q.pop();
    return x;
  }

  int top() { return q.front(); }

  bool empty() { return q.empty(); }
};

int main() {}