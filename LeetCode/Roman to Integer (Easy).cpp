/*
Source: https://leetcode.com/problems/roman-to-integer/
Title: Roman to Integer
Diff: Easy

Instruction
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

Example
Input: s = "III"
Output: 3
Explanation: III = 3.

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(std::string s) {
            std::unordered_map<char, int> m = {
                    {'I', 1},
                    {'V', 5},
                    {'X', 10},
                    {'L', 50},
                    {'C', 100},
                    {'D', 500},
                    {'M', 1000}
            };

            int res = 0;
            for(int i = 0;  i < s.size(); i++) {
                if (int val = m[s[i]]; val < m[s[i+1]]) {
                    res -= val;
                } else {
                    res += val;
                }
            }
            return res;
        }
};

int main() {
    Solution solution;
    int testcase1 = 3;
    assert(solution.romanToInt("III") ==  testcase1);
    int testcase2 = 58;
    assert(solution.romanToInt("LVIII") ==  testcase2);
    int testcase3 = 1994;
    assert(solution.romanToInt("MCMXCIV") ==  testcase3);   
    cout << "solution has passed all of the defined testcases";
    return 0;
}

/*
Reference: https://leetcode.com/problems/roman-to-integer/discuss/2681091/C%2B%2B-17-unordered_map-iterators

My original solution: work on windows but got stack buffer overflow on leetcode (but there's a hint of false positives)
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        string symbols = "IVXLCDM";
        int prevIdx = 0;
        int nextIdx = 0;
        int idxSep = 0;
        int count = 0;
        for(int i = 0; i <= s.size(); i++) {
            prevIdx = findIndex(s[i], symbols);
            nextIdx = findIndex(s[i+1], symbols);
            idxSep = nextIdx - prevIdx;
            if(idxSep == 1 || idxSep == 2) {
                res += (findVal(s[i+1]) - findVal(s[i]));
                i++;
            } else {
                res += (findVal(s[i]));
            }
        }
        return res;
    };
    
    int findIndex(char c, string s) {
        for(int i = 0; i < s.size(); i++) {
            if(c == s[i])
                return i;
        }
        return -1;
    }
    
    int findVal(char c) {
        switch(c) {
            case 'I':
                return 1;
                break;
            case 'V':
                return 5;
                break;
            case 'X':
                return 10;
                break;
            case 'L':
                return 50;
                break;
            case 'C':
                return 100;
                break;
            case 'D':
                return 500;
                break;
            case 'M':
                return 1000;
                break;
        }
        return 0;
    }
};

*/