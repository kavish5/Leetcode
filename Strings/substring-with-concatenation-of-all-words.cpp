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
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    if (s.empty() || words.empty()) {
      return result;
    }
    unordered_map<string, int> wordCount;
    for (auto word : words) {
      wordCount[word]++;
    }
    int strLength = s.length();
    int totalWords = words.size();
    int wordLength = words[0].size();
    for (int i = 0; i < wordLength; i++) {
      unordered_map<string, int> curCount;
      int left = i, count = 0;
      for (int j = i; j <= strLength - wordLength; j += wordLength) {
        string word = s.substr(j, wordLength);
        if (wordCount.count(word)) {
          curCount[word]++;
          if (curCount[word] <= wordCount[word]) {
            count++;
          } else {
            while (curCount[word] > wordCount[word]) {
              string leftWord = s.substr(left, wordLength);
              curCount[leftWord]--;
              if (curCount[leftWord] < wordCount[leftWord]) {
                count--;
              }
              left += wordLength;
            }
          }
          if (count == words.size()) {
            result.push_back(left);
            curCount[s.substr(left, wordLength)]--;
            count--;
            left += wordLength;
          }
        } else {
          curCount.clear();
          count = 0;
          left = j + wordLength;
        }
      }
    }
    return result;
  }

  vector<int> findSubstringOld(string s, vector<string>& words) {
    vector<int> res;
    if (s.empty() || words.empty()) {
      return res;
    }
    unordered_map<string, int> wordCount;
    for (auto word : words) {
      wordCount[word]++;
    }
    int strLength = s.length();
    int totalWords = words.size();
    int wordLength = words[0].size();
    for (int i = 0; i <= strLength - totalWords * wordLength; i++) {
      unordered_map<string, int> substringCount;
      int j = 0;
      for (; j < totalWords; j++) {
        string word = s.substr(i + j * wordLength, wordLength);
        if (wordCount.find(word) == wordCount.end()) {
          break;
        } else {
          substringCount[word]++;
          if (substringCount[word] > wordCount[word]) {
            break;
          }
        }
      }
      if (j == totalWords) {
        res.push_back(i);
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  string s = "wordgoodgoodgoodbestword";
  vector<string> words = {"word", "good", "best", "good"};
  cout << sol.findSubstring(s, words) << endl;
  return 0;
}