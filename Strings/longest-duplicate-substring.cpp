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
  int prime = 100001;
  vector<int> power;

 public:
  // string longestDupSubstring(string s) {
  //   TrieNode trie;
  //   int maxCount = 0;
  //   int maxCountIndex = 0;
  //   for (int i = 0; i < s.length(); i++) {
  //     int count = trie.insert(s.substr(i));
  //     if (count > maxCount) {
  //       maxCount = count;
  //       maxCountIndex = i;
  //     }
  //   }
  //   return s.substr(maxCountIndex, maxCount);
  // }

  string longestDupSubstring(string s) {
    int n = s.length();
    int l = 0, r = n - 1;
    power = vector<int>(n);
    power[0] = 1;
    for (int i = 1; i < n; i++) {
      power[i] = (power[i - 1] * 26) % prime;
    }
    string res;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      string cur = rabinKarp(s, mid);
      if (cur.length() > res.length()) {
        res = cur;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return res;
  }

  string rabinKarp(string& s, int len) {
    if (len == 0) {
      return "";
    }
    int n = s.length();
    int cur = 0;
    unordered_map<int, vector<int>> hash;
    for (int i = 0; i < len; i++) {
      cur = (cur * 26 + (s[i] - 'a')) % prime;
    }
    hash[cur] = {0};
    for (int i = len; i < n; i++) {
      cur =
          ((cur - power[len - 1] * (s[i - len] - 'a')) % prime + prime) % prime;
      cur = (cur * 26 + (s[i] - 'a')) % prime;
      if (hash.find(cur) == hash.end()) {
        hash[cur] = {i - len + 1};
      } else {
        for (int index : hash[cur]) {
          string str = s.substr(i - len + 1, len);
          if (s.substr(index, len) == str) {
            return s.substr(index, len);
          }
        }
        hash[cur].push_back({i - len + 1});
      }
    }
    return "";
  }
};

int main() {
  Solution sol;
  string input = "banana";
  cout << sol.longestDupSubstring(input) << endl;
  return 0;
}