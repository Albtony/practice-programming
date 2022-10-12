/*
Source: https://leetcode.com/problems/length-of-last-word/
Title: Length of Last Word
Diff: Easy

Instruction
Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.

Example
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        string::iterator it;
        int count = 0;
        bool wordIsFound = false;

        // read string from back to front
        for(int i = s.size()-1; i >= 0; i--) {
            if(s[i] != ' ' && !wordIsFound) wordIsFound = true;
            if(wordIsFound) {
                if(s[i] != ' ') count++;
                else return count;
            }
        }
        return count;
    }
};

int main() {
    Solution solution;

    int testcase1 = 5;
    assert(solution.lengthOfLastWord("Hello World") == testcase1);
    int testcase2 = 4;
    assert(solution.lengthOfLastWord("   fly me   to   the moon  ") == testcase2);
    int testcase3 = 6;
    assert(solution.lengthOfLastWord("luffy is still joyboy") == testcase3);
    cout << "solution has passed all of the defined testcases";

    return 0;
}