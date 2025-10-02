/*
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving 
the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Explanation:
The strings s and t can be made identical by:
Mapping 'e' to 'a'.
Mapping 'g' to 'd'.

Example 2:
Input: s = "foo", t = "bar"
Output: false

Explanation:
The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:
Input: s = "paper", t = "title"
Output: true

Constraints:
1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        bool result = true;
        if (s.length() != t.length()) 
            result = false;
        map<char, char> m;
        set<char> used;

        for (int i = 0; i < s.length(); i++) {
            if (m.find(s[i]) == m.end()) {
                if (used.count(t[i]))
                    return false;
                m[s[i]] = t[i];
                used.insert(t[i]);
            } else if (m[s[i]] != t[i]) {
                return false;
            } 
        }
        
        return result;
    }
};

int main() {
    Solution sol;

    assert(sol.isIsomorphic("foo", "bar") == false);
    assert(sol.isIsomorphic("egg", "add") == true);
    assert(sol.isIsomorphic("abba", "popo") == false);
    assert(sol.isIsomorphic("bada", "badc") == false);
    assert(sol.isIsomorphic("paper", "title") == true);
    cout << "solution has passed all of the defined testcases";

    return 0;
}

/* write up
isomprohic strings means that s and t can be transformed to each other by mapping their characters
with a condition where each char must be mapped into only 1 char at max.

this means that, s and t must have the same length,
and we must map each char, and ensure ther is no double up

so, just check if s and t has the same length or not, it will give us a shortcut and eliminate any index problem
and then use map and a set to map and maintain seen mapped chars.
*/