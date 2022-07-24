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
  string validateIPAddress(string IP) {
    if (count(IP.begin(), IP.end(), '.') == 3) {
      if (IP[IP.size() - 1] == '.') {
        return "Neither";
      }
      stringstream ss(IP);
      string token;
      while (getline(ss, token, '.')) {
        if (token.length() == 0 || token.length() > 3) {
          return "Neither";
        }
        if (token[0] == '0' && token.length() != 1) {
          return "Neither";
        }
        for (char c : token) {
          if (!isdigit(c)) {
            return "Neither";
          }
        }
        if (stoi(token) > 255) {
          return "Neither";
        }
      }
      return "IPv4";
    } else if (count(IP.begin(), IP.end(), ':') == 7) {
      if (IP[IP.size() - 1] == ':') {
        return "Neither";
      }
      stringstream ss(IP);
      string token;
      while (getline(ss, token, ':')) {
        if (token.length() == 0 || token.length() > 4) {
          return "Neither";
        }
        for (char c : token) {
          if (!isxdigit(c)) {
            return "Neither";
          }
        }
      }
      return "IPv6";
    }
    return "Neither";
  }
};

int main() {
  Solution sol;
  string S = "12.1.33.4";
  cout << sol.validateIPAddress(S) << endl;
  return 0;
}