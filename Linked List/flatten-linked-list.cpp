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

class Node {
 public:
  int val;
  Node* prev;
  Node* next;
  Node* child;
};

class Solution {
 public:
  Node* flatten(Node* head) {
    if (head) {
      flattenRec(head);
    }
    return head;
  }

  Node* flattenRec(Node* head) {
    Node* cur = head;
    Node* tail = head;
    while (cur) {
      Node* child = cur->child;
      Node* next = cur->next;
      if (child) {
        Node* _tail = flattenRec(child);
        _tail->next = next;
        if (next) {
          next->prev = _tail;
        }
        cur->next = child;
        child->prev = cur;

        cur->child = nullptr;
        cur = _tail;
      } else {
        cur = next;
      }
      if (cur) {
        tail = cur;
      }
    }
    return tail;
  }
};

int main() {
  Solution sol;
  Node* head = new Node(1);
  cout << sol.flatten(head) << endl;
  return 0;
}