#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
  // T.C.=O(N) S.C.=O(No. of unique chars in string)
    int longestKSubstr(string s, int k) {
        int n = s.size();
        if (n < k) return -1;

        unordered_map<char, int> freq;
        int left = 0, right = 0;
        int maxLength = -1;

        while (right < n) {
            freq[s[right]]++;

            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }

            if (freq.size() == k) {
                maxLength = max(maxLength, right - left + 1);
            }

            right++;
        }

        return maxLength;

    }
};
