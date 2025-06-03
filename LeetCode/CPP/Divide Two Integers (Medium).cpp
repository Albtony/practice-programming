/*
Source: https://leetcode.com/problems/Divide Two Integers/
Title: Divide Two Integers
Diff: Medium

Instruction
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be 
truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. 
For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, 
then return -231.

Example
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.

Constraints
-231 <= dividend, divisor <= 231 - 1
divisor != 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        uint64_t proc_dividend = abs(dividend);
        uint64_t proc_divisor = abs(divisor);
        uint64_t base_res = 1;
        uint64_t step_res = 1;
        int64_t res = 0;

        
        if(proc_divisor > proc_dividend) return 0;
        while(proc_dividend > proc_divisor) {
            proc_dividend -= proc_divisor;
            res += step_res;
            step_res += step_res;
            proc_divisor += proc_divisor;
        }

        proc_divisor = abs(divisor);
        step_res = 1;

        while(proc_dividend < 0) {
            proc_dividend += proc_divisor;
            res -= step_res;
            step_res += step_res;
            proc_divisor += proc_divisor;
        }

        while(proc_dividend >= proc_divisor) {
            proc_dividend -= proc_divisor;
            res++;
        }

        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            res = -1 * res;

        if(res > INT32_MAX) res = INT32_MAX;
        if(res < INT32_MIN) res = INT32_MIN;

        return res;
    }
};

int main() {
    Solution solution;

    int64_t test_dividend, test_divisor;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(INT32_MIN + 1, INT32_MAX - 1);

    for(int i = 0; i < 1000; i++) {
        test_dividend = distr(gen);
        test_divisor = distr(gen);
        assert(solution.divide(test_dividend, test_divisor) == (int)(test_dividend/test_divisor));
    }
    
    cout << "solution has passed all of the defined testcases";

    return 0;
}

/*
    much better and elegant answer
    https://leetcode.com/problems/divide-two-integers/discuss/1516367/Complete-Thinking-Process-or-Intuitive-Explanation-or-All-rules-followed-or-C%2B%2B-code


 	int divide(int dividend, int divisor) {
        if(dividend == divisor)
            return 1;
        bool isPositive = (dividend<0 == divisor<0);    // if both are of same sign, answer is positive
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        unsigned int ans = 0;
        while(a >= b){  // while dividend is greater than or equal to divisor
            short q = 0;
            while(a > (b<<(q+1)))
                q++;
            ans += (1<<q);  // add the power of 2 found to the answer
            a = a - (b<<q);  // reduce the dividend by divisor * power of 2 found
        }
        if(ans == (1<<31) and isPositive)   // if ans cannot be stored in signed int
            return INT_MAX;
        return isPositive ? ans : -ans;
    } 
 */