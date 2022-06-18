/*
1 + 1 = 10; carry 1
10 + 1 = 11; carry 1
1 + 0 = 1; carry 0
0 + 1 = 1; carry 0
0 + 0 = 0; carry 0
1 can be carry
*/
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

class Solution {
 public:
  string addBinary(string a, string b) {
    if (a.length() > b.length()) {
      return addBinary(b, a);
    }

    int diff = b.length() - a.length();

    string padding;
    for (int i = 0; i < diff; i++) padding.push_back('0');

    a = padding + a;
    string res;
    char carry = '0';

    for (int i = a.length() - 1; i >= 0; i--) {
      if (a[i] == '1' && b[i] == '1') {
        res.push_back(carry);
        if (carry == '0') {
          carry = '1';
        }
      } else if (a[i] != b[i]) {
        if (carry == '1') {
          res.push_back('0');
        } else {
          res.push_back('1');
        }
      } else {
        res.push_back(carry);
        carry = '0';
      }
    }
    res.push_back(carry);
    reverse(res.begin(), res.end());

    int index = 0;
    while (index + 1 < res.length() && res[index] == '0') index++;
    return (res.substr(index));
  }
};

int main() {
  string a = "1101", b = "100";
  Solution s;
  cout << s.addBinary(a, b) << endl;
  return 0;
}