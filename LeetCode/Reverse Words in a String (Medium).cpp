/*
Source: https://leetcode.com/problems/reverse-words-in-a-string/
Title: Reverse Words in a String
Diff: Medium

Instruction
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only 
have a single space separating the words. Do not include any extra spaces.

Example
Input: s = "the sky is blue"
Output: "blue is sky the"

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Constraints
1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        s = normalize(s);
        string res = "";
        char *dup = strdup(s.c_str());
        char *token = strtok(dup, " ");
        while(token != NULL) {
            res.insert(0, token);
            res.insert(0, 1, ' ');
            token = strtok(NULL, " ");
        }

        if(res.length() > 1) res = res.substr(1, res.length()-1);
        return res;
    }

    string normalize(string s) {
        string res = "";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                i++;
                while(s[i] == ' ') i++;
                i--;
            }
            res.push_back(s[i]);
        }
        res.erase(res.find_last_not_of(" \n\r\t")+1);
        return res;
    }
};

int main() {
    Solution solution;
    string testcase1 = "blue is sky the";
    assert(solution.reverseWords("the sky is blue") == testcase1);
    string testcase2 = "world hello";
    assert(solution.reverseWords("  hello world  ") == testcase2);
    string testcase3 = "example good a";
    assert(solution.reverseWords("a good   example") == testcase3);
    string testcase4 = "a b c d e f g";
    assert(solution.reverseWords("g f e d c b a") == testcase4);
    string testcase5 = "a";
    assert(solution.reverseWords("   a   ") == testcase5);
    string testcase6 = "ccc bbb aaa";
    assert(solution.reverseWords("  aaa   bbb     ccc  ") == testcase6);
    
    cout << "solution has passed all of the defined testcases";
    return 0;
}
