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
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (!node) {
      return NULL;
    }
    unordered_map<int, Node*> visited;
    return graphClone(node, visited);
  }

  Node* graphClone(Node* node, unordered_map<int, Node*>& visited) {
    Node* newNode = new Node(node->val);
    visited.insert({node->val, newNode});

    for (Node* n : node->neighbors) {
      auto it = visited.find(n->val);
      if (it == visited.end()) {
        Node* cn = graphClone(n, visited);
        newNode->neighbors.push_back(cn);
      } else {
        newNode->neighbors.push_back(it->second);
      }
    }
    return newNode;
  }
};

int main() {
  Solution sol;
  Node* root = new Node(1);
  cout << sol.cloneGraph(root) << endl;
  return 0;
}