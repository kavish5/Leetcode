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
 public:
  void solve(vector<vector<char>>& board) {
    int R = board.size();
    int C = board[0].size();
    if (R <= 2 || C <= 2) {
      return;
    }
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (board[i][j] == 'O' &&
            (i == 0 || j == 0 || i == R - 1 || j == C - 1)) {
          dfs(board, i, j, R, C);
        }
      }
    }
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (board[i][j] == 'K') {
          board[i][j] = 'O';
        } else if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }

  void dfs(vector<vector<char>>& board, int i, int j, int R, int C) {
    if (i >= 0 && i < R && j >= 0 && j < C && board[i][j] == 'O') {
      board[i][j] = 'K';
      dfs(board, i - 1, j, R, C);
      dfs(board, i + 1, j, R, C);
      dfs(board, i, j - 1, R, C);
      dfs(board, i, j + 1, R, C);
    }
  }
};

int main() {
  Solution sol;
  vector<vector<char>> board = [
    [ "X", "X", "X", "X" ], [ "X", "O", "O", "X" ], [ "X", "X", "O", "X" ],
    [ "X", "O", "X", "X" ]
  ];
  cout << sol.solve(board) << endl;
  return 0;
}