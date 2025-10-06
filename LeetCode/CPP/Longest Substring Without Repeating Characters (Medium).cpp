/*
Source: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
Diff: Medium

Given a string s, find the length of the longest substring without duplicate characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0;
        int curr = 0;
        for (int i = 0; i < s.length(); i++) {
            mx = max(curr, mx);
            curr = 0;
            set<char> seen;
            for (int j = i; j < s.length(); j++) {
                if (!seen.contains(s[j])){
                    seen.insert(s[j]);
                    curr++;
                } else {
                    break;
                }
            }
        }

        return max(curr, mx);
    }

    int betterLengthOfLongestSubstring(string s) {
        int head = 0;
        int tail = 0;
        int mx = 0;
        set<char> seen;
        while (head < s.size()) {
            if (!seen.contains(s[head])) {
                seen.insert(s[head]);
                mx = max(mx, head - tail + 1); 
                head++;
            } else {
                while (s[tail] != s[head]) {
                    seen.erase(s[tail]);
                    tail++;
                }   
                tail++;
                head++;
            } 
        }

        return max(mx, head - tail);
    }
};

int main() {
    Solution sol;

    assert(sol.lengthOfLongestSubstring("aaaa") == 1);
    assert(sol.lengthOfLongestSubstring("abc") == 3);
    assert(sol.lengthOfLongestSubstring("aabc") == 3);
    assert(sol.lengthOfLongestSubstring("abcabcbb") == 3);
    assert(sol.lengthOfLongestSubstring("pwwkew") == 3);
    assert(sol.lengthOfLongestSubstring(" ") == 1);
    assert(sol.lengthOfLongestSubstring("") == 0);
    cout << "solution has passed all of the defined testcases";

    return 0;
}

/*
1st solution is using a naive bruteforce approach, where i check the best unique substring for each s[i]
from start to finish, which lead to O(n^2) time complexity which is very unoptimal

2nd solution is much better and more standard approach to this problem, using a sliding window with 2 pointers
head and tail, the process is simple, just move the head every iteration until it finds a duplicate,
if so, then the tail will move forward until s[head] is no longer a duplicate, hence maintaining uniqueness
without needing to do a double loop, which leads to O(n) time complexity.
*/