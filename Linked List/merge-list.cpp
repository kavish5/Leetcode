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

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == NULL) {
      return list2;
    }
    if (list2 == NULL) {
      return list1;
    }
    ListNode* ptr = list1;
    if (list1->val > list2->val) {
      ptr = list2;
      list2 = list2->next;
    } else {
      list1 = list1->next;
    }
    ListNode* cur = ptr;
    while (list1 && list2) {
      if (list1->val < list2->val) {
        cur->next = list1;
        list1 = list1->next;
      } else {
        cur->next = list2;
        list2 = list2->next;
      }
      cur = cur->next;
    }
    if (!list1) {
      cur->next = list2;
    } else {
      cur->next = list1;
    }
    return ptr;
  }
};

int main() {
  Solution sol;
  ListNode* list1 = new ListNode(1);
  list1->next = new ListNode(2);
  list1->next->next = new ListNode(3);
  list1->next->next->next = new ListNode(4);
  list1->next->next->next->next = new ListNode(5);
  list1->next->next->next->next->next = new ListNode(6);
  list1->next->next->next->next->next->next = new ListNode(7);
  list1->next->next->next->next->next->next->next = new ListNode(8);
  ListNode* list2 = new ListNode(1);
  list2->next = new ListNode(20);
  list2->next->next = new ListNode(30);
  list2->next->next->next = new ListNode(40);
  cout << sol.mergeTwoLists(list1, list2) << endl;
  return 0;
}