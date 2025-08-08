/*
Source: https://leetcode.com/problems/pascals-triangle-ii/description/
Diff: Easy

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:
Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]

Constraints:
0 <= rowIndex <= 33
Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result = {};
        for (int i = 0; i <= rowIndex; i++) result.push_back(getCombination(rowIndex, i));
        return result;
    }

    // For large combinations, computing factorials directly risks overflow.
    // Instead of calculating n! / (r!(n−r)!), we reduce it to (r+1 to n) / (1 to n−r).
    // Then we apply GCD-based pairwise reduction to simplify numerator and denominator factors
    // before multiplying, ensuring a safer and more efficient result.
    int getCombination(int object, int sample) {
        vector<int> topMembers = facMembers(sample, object);
        vector<int> botMembers = facMembers(1, object-sample);
        unsigned long long result = 1;
        for (int i = 0; i < topMembers.size(); i++) {
            result *= topMembers[i];
            for (int j = 0; j < botMembers.size(); j++) {
                int divisor = gcd(result, botMembers[j]);
                botMembers[j] /= divisor;
                result /= divisor;
            }
            botMembers.erase(
                std::remove(botMembers.begin(), botMembers.end(), 1),
                botMembers.end()
            );
        }
        return result;
    } 

    vector<int> facMembers (int start, int end) {
        vector<int> res = {};
        for (int i = start+1; i <= end; i++) res.push_back(i);
        return res; 
    }
};

int main() {
    Solution solution;
    
    vector<int> test0 = {1};
    vector<int> test1 = {1, 1};
    vector<int> test2 = {1, 2, 1};
    vector<int> test3 = {1, 3, 3, 1};
    vector<int> test4 = {1,31,465,4495,31465,169911,736281,2629575,7888725,20160075,44352165,84672315,141120525,206253075,265182525,300540195,300540195,265182525,206253075,141120525,84672315,44352165,20160075,7888725,2629575,736281,169911,31465,4495,465,31,1};
    vector<int> test5 = {1,32,496,4960,35960,201376,906192,3365856,10518300,28048800,64512240,129024480,225792840,347373600,471435600,565722720,601080390,565722720,471435600,347373600,225792840,129024480,64512240,28048800,10518300,3365856,906192,201376,35960,4960,496,32,1};

    assert(solution.getRow(0) == test0);
    assert(solution.getRow(1) == test1);
    assert(solution.getRow(2) == test2);
    assert(solution.getRow(3) == test3);
    assert(solution.getRow(31) == test4);
    assert(solution.getRow(32) == test5);

    cout << "solution has passed all of the defined testcases";
}