/*
Source: https://leetcode.com/problems/valid-palindrome/
Diff: Easy

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

Constraints:
1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        s = toAlnum(s);
        int l = 0, r = s.size() - 1;
        // two pointer approach, its just a fancy name for checking with 2 index like an old man;
        while (l < r) 
            if (s[l++] != s[r--])
                return false; 
        return true;
    }

    string toAlnum(string s) {
        string result = "";
        transform(s.begin(), s.end(), s.begin(), [](char c){return tolower(c);});
        for (char c : s) 
            if (isalnum(c))
                result.push_back(c);
        return result;
    }
};

int main() {
    Solution solution;

    assert(solution.isPalindrome("A man, a plan, a canal: Panama") == true);
    assert(solution.isPalindrome("race a car") == false);
    assert(solution.isPalindrome(" ") == true);

    cout << "solution has passed all of the defined testcases";
}