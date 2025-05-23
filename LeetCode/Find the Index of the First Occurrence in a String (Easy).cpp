/*
Source: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
Title: Find the Index of the First Occurrence in a String
Diff: Easy

Instruction
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.

Examples
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints
1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // naive sliding window approach, O(n^2) time, O(1) space
        int strStr(string haystack, string needle) {
            int i = 0;
            int j = 0;
            while(i < haystack.size() && j < needle.size()) {
                if (haystack[i] == needle[j]) {
                    i++;
                    j++;
                    cout << i << " " << j << endl;
                    continue;
                } else {
                    i -= j;
                    j = 0;
                }
                i++;
            }
    
            if (j == needle.size()) {
                return i - needle.size();
            } else {
                return -1;
            }
        }
    // O(n) time, O(n) space, knuth-morris-pratt algorithm
        int betterStrStr(string haystack, string needle) {
            int n = haystack.size();
            int m = needle.size();
    
            if (m == 0) {
                return 0;
            }
    
            vector<int> lps = lpsConstructor(needle);
            int i = 0; 
            int j = 0; 
    
            while (i < n) {
                if (haystack[i] == needle[j]) {
                    i++;
                    j++;
                }
    
                if (j == m) {
                    return i - j; 
                } else if (i < n && haystack[i] != needle[j]) {
                    if (j != 0) {
                        j = lps[j - 1]; 
                    } else {
                        i++; 
                    }
                }
            }
    
            return -1; 
        }

        vector<int> lpsConstructor(string needle) {
            int n = needle.size(); 
            vector<int> lps(n, 0);

            int len = 0;
            int i = 1;
            while (i < n) {
                if (needle[i] == needle[len]) {
                    len++;
                    lps[i] = len;
                    i++;
                } else {
                    if (len != 0) {
                        len = lps[len-1];
                    } else {
                        lps[i] = 0;
                        i++;
                    }
                }
            }
            return lps;
        }
    
};

int main () {
    Solution solution;

    string haystack1 = "sadbutsad";
    string needle1 = "sad";
    assert(solution.betterStrStr(haystack1, needle1) == 0);

    string haystack2 = "leetcode";
    string needle2 = "leeto";
    assert(solution.betterStrStr(haystack2, needle2) == -1);

    string haystack3 = "hey";
    string needle3 = "";
    assert(solution.betterStrStr(haystack3, needle3) == 0);

    string haystack4 = "ababaabbbbababbababbabaabbabaab";
    string needle4 = "abbabbb";
    assert(solution.betterStrStr(haystack4, needle4) == -1);
    cout << "solution has passed all of the defined testcases";

    return 0;
}


/**
 * The Knuth-Morris-Pratt (KMP) algorithm optimizes string searching by preventing redundant checks. Unlike the naive approach, 
 * KMP avoids backtracking in the haystack when a mismatch occurs with the pattern. Instead, KMP intelligently backtracks only within 
 * the pattern using the Longest Proper Prefix which is also a Suffix (LPS) array.
 *
 * This smart backtracking leads to a time complexity of O(m+n) for KMP, where 'n' is the length of the haystack and 'm' is the 
 * length of the needle. In contrast, the naive approach, which backtracks in both the haystack and the pattern, results in a 
 * worst-case time complexity of O(mn).
 *
 * KMP achieves its efficiency through the use of the LPS array. This array stores, for each index 'i' in the pattern, 
 * the length of the longest proper prefix of the pattern (from index 0 to 'i') that is also a suffix of the same substring.
 *
 * This precomputed information allows KMP to shift the pattern forward more efficiently upon a mismatch. By knowing 
 * the length of the longest matching proper prefix that is also a suffix, KMP can skip comparisons with characters that are already known to match.
 *
 * The naive approach, on the other hand, simply shifts the pattern by one position after a mismatch. This can lead to 
 * redundant comparisons, especially when the pattern contains repeating sub-patterns, thus worsening its worst-case time complexity.
 */
