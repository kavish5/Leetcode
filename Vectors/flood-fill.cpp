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
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int color) {
    if (image[sr][sc] == color) {
      return image;
    }
    fill(image, sr, sc, color, image[sr][sc]);
    return image;
  }

  void fill(vector<vector<int>>& image, int sr, int sc, int newColor,
            int oldColor) {
    if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() ||
        oldColor != image[sr][sc]) {
      return;
    }
    image[sr][sc] = newColor;
    fill(image, sr + 1, sc, newColor, oldColor);
    fill(image, sr - 1, sc, newColor, oldColor);
    fill(image, sr, sc + 1, newColor, oldColor);
    fill(image, sr, sc - 1, newColor, oldColor);
  }
};

int main() {
  Solution sol;
  vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 0}};
  int sr = 1;
  int sc = 1;
  int color = 2;
  cout << sol.floodFill(image, sr, sc, color) << endl;
  return 0;
}