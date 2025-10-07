/*
Source: https://leetcode.com/problems/zigzag-conversion/description/
Diff: Medium

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:
Input: s = "A", numRows = 1
Output: "A"

Constraints:
1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
*/


#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string res = "";

        if (numRows == 1) return s;
        for (int i = 0; i < numRows; i++) {
            int cycle = (numRows*2) - 2 - (i*2);
            for (int j = i; j < s.size(); j += cycle) {
                res += s[j];
                if (i != 0 && j != i) {
                    j += (i * 2);
                    if (j < s.size())
                        res += s[j];
                }
                if (cycle == 0) {
                    j += (i * 2);
                }
            }
        }
        return res;
    }
};


int main() {
    Solution sol;

    assert(sol.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    assert(sol.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    assert(sol.convert("A", 1) == "A");
    assert(sol.convert("AB", 1) == "AB");
    assert(sol.convert("AB", 100) == "AB");
    cout << "solution has passed all of the defined testcases";

    return 0;
}

/*
its deceptively tricky

the core idea is simple, to print a string in a zig zag pattern, then read it sideways like how normal people do
so, we just need to find out the indexing pattern to print a linear string to the requested format

and the basic pattern goes like this

P     I     N  -> result is PINALSIGYAHRPI
A   L S   I G
Y A   H R
P     I

its basically an outward march from the top most initial point (PIN)
for visualization purpose, see below

P   A   Y   P   A   L   I   S   H   I   R   I   N   G
1                       2                       3   
    4               5       6               7       8
        9       10              11      12             
            13                      14

so, its simply a series of jumps and a little bit tweaks here and there to get the correct pattern
so, the distance between the big jumps is defined by the rows (P to I), (I to G) which is 2 * row - 2
but for every row you go down, the jump become smaller, and there is a small jump between the big jumps
it start at 0 (the first row has no small jumps), then progressively gets bigger by 2 each time

so we have 2 dynamic jumps
- big -> start at 2*row - 2, substract 2 for every row
- small -> start at 0, adds 2 for every row

so just model that, and we dandy!
there is probably a better approach, but this works for me :D
*/  