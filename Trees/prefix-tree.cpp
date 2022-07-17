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

class Trie {
  Trie* children[26];
  bool isEndOfWord;

 public:
  Trie() {
    isEndOfWord = false;
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
  }

  void insert(string word) {
    Trie* cur = this;
    for (char c : word) {
      if (!(cur->children[c - 'a'])) {
        cur->children[c - 'a'] = new Trie();
      }
      cur = cur->children[c - 'a'];
    }
    cur->isEndOfWord = true;
  }

  bool search(string word) {
    Trie* cur = this;
    for (char c : word) {
      cur = cur->children[c - 'a'];
      if (!cur) {
        return false;
      }
    }
    return cur->isEndOfWord;
  }

  bool startsWith(string prefix) {
    Trie* cur = this;
    for (char c : prefix) {
      cur = cur->children[c - 'a'];
      if (!cur) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Trie* obj = new Trie();
  string word = "word";
  string prefix = "wor";
  obj->insert(word);
  cout << obj->search(word) << endl;
  cout << obj->startsWith(prefix) << endl;
  return 0;
}