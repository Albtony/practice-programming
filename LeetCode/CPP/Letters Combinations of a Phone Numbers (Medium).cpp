/*
Source: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
Diff: Medium

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that 
the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does 
not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]

Constraints:
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

#include <map>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> lookup = {
            {'0', " "},
            {'1', ""},
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> v;
        queue<string> q;

        for(int i = 0; i < digits.size(); i++) {
            string digitString = lookup[digits[i]];
            if (q.empty()) q.push("");
            int qSize = q.size();
            for (int j = 0; j < qSize; j++) {
                string temp = q.front();
                q.pop();
                for(int k = 0; k < digitString.size(); k++) {
                    q.push(temp + digitString[k]);
                }
            }
        }

        while (!q.empty()) {
            v.push_back(q.front());
            q.pop();
        }

        return v;
    }
};

int main() {
    Solution sol;
    cout << sol.letterCombinations("23").size();
    return 0;
}

/*
this problem basically ask you to create a combination of mutually exclusive elements

so its basically a * b * ... * n
where a...n is the num of elements that are mapped to a certain digit

and since a is not necessarily equal to b and other counts
there is no known easy linear trick to solve this problem efficiently

so we need to actually traverse every path and hence the nested loops and the seemingly high time complexity
but its necessary y'know ¯\_(ツ)_/¯

imagine that we are asked to construct the combination of mapped characters of m digits
in a conventional nested loop style of programming, you'd have to write m loops
which sux, and it doesnt improve the time complexity from bfs o(n^m)

so these 3 loops is actually is pretty good,
the way it works is basically dynamically looping over the digits, like how bfs would
yes, this is essentially a bfs implementation

we treat each digit as levels, and traverse all possible path for each level until we reach the bottom (leaves)
that leaves us with all complete possible combinations

here is a visualization of it
root (""/blank)
        ├── "a"
        │   ├── "ad"
        │   ├── "ae"
        │   └── "af"
        ├── "b"
        │   ├── "bd"
        │   ├── "be"
        │   └── "bf"
        └── "c"
            ├── "cd"
            ├── "ce"
            └── "cf"
*/