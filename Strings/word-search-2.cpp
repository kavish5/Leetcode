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
#include <unordered_set>
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
 public:
  Trie* children[26];
  bool endOfWord;

  Trie() : endOfWord(false) {
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
  }

  ~Trie() {
    for (int i = 0; i < 26; i++) {
      if (children[i]) {
        delete children[i];
      }
    }
  }

  void insert(string word) {
    Trie* cur = this;
    for (char c : word) {
      if (cur->children[c - 'a'] == nullptr) {
        cur->children[c - 'a'] = new Trie();
      }
      cur = cur->children[c - 'a'];
    }
    cur->endOfWord = true;
  }
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    if (words.size() == 0) {
      return {};
    }
    Trie trie;
    int r = board.size();
    int c = board[0].size();
    for (string w : words) {
      trie.insert(w);
    }
    unordered_set<string> result;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        dfs(board, i, j, result, &trie, "");
      }
    }
    vector<string> resultV(result.begin(), result.end());
    return resultV;
  }

  void dfs(vector<vector<char>>& board, int x, int y,
           unordered_set<string>& result, Trie* root, string word) {
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() ||
        board[x][y] == ' ')
      return;

    if (root->children[board[x][y] - 'a'] != NULL) {
      word = word + board[x][y];
      root = root->children[board[x][y] - 'a'];
      if (root->endOfWord) result.insert(word);
      char c = board[x][y];
      board[x][y] = ' ';
      dfs(board, x + 1, y, result, root, word);
      dfs(board, x - 1, y, result, root, word);
      dfs(board, x, y + 1, result, root, word);
      dfs(board, x, y - 1, result, root, word);
      board[x][y] = c;
    }
  }
};

int main() {
  Solution sol;
  vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
                                {'e', 't', 'a', 'e'},
                                {'i', 'h', 'k', 'r'},
                                {'i', 'f', 'l', 'v'}};
  vector<string> words = {"oath", "pea", "eat", "rain"};
  cout << sol.findWords(board, words) << endl;
  return 0;
}