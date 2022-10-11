/*
Source: https://leetcode.com/problems/longest-common-prefix/
Title: Longest Common Prefix
Diff: Easy

Instruction
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example
Input: strs = ["flower","flow","flight"]
Output: "fl"

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for(int i = 0; i < strs[0].size(); i++) {
            int check = 0;
            prefix.push_back(strs[0][i]);
            for(auto str : strs) {
                if(str.find(prefix) == 0) check++;
            }
            if(check != strs.size()) {
                prefix.pop_back();
                break;
            }
        }
        return prefix;
    }
};


int main() {
    Solution solution;
    vector<string> v1 = {"c","acc","ccc"};
    string testcase1 = "";
    assert(solution.longestCommonPrefix(v1) == testcase1);
    vector<string> v2 = {""};
    string testcase2 = "";
    assert(solution.longestCommonPrefix(v2) == testcase2);
    vector<string> v3 = {"a"};
    string testcase3 = "a";
    assert(solution.longestCommonPrefix(v3) == testcase3);
    vector<string> v4 = {"flower", "flow", "flight"};
    string testcase4 = "fl";
    assert(solution.longestCommonPrefix(v4) == testcase4);
    vector<string> v5 = {"flower", "flower", "flower"};
    string testcase5 = "flower";
    assert(solution.longestCommonPrefix(v5) == testcase5);
    cout << "solution has passed all of the defined testcases";
    return 0;
}