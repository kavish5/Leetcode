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

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string, multiset<string>> adj;
    for (vector<string> t : tickets) {
      adj[t[0]].insert(t[1]);
    }
    vector<string> result;
    dfs(adj, result, "JFK");
    reverse(result.begin(), result.end());
    return result;
  }

  void dfs(unordered_map<string, multiset<string>>& adj, vector<string>& result,
           string s) {
    while (adj[s].size()) {
      string v = *(adj[s].begin());
      adj[s].erase(adj[s].begin());
      dfs(adj, result, v);
    }
    result.push_back(s);
  }
};

int main() {
  Solution sol;
  vector<vector<string>> tickets = {{"JFK", "SFO"},
                                    {"JFK", "ATL"},
                                    {"SFO", "ATL"},
                                    {"ATL", "JFK"},
                                    {"ATL", "SFO"}};
  cout << sol.findItinerary(tickets) << endl;
  return 0;
}