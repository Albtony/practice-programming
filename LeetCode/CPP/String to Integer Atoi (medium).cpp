#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
        int myAtoi(string s) {
        int res = 0;
        bool isNegative = false;
        bool isInitialized = false;
        for(auto ch : s) {
            if(ch == ' ' && !isInitialized) continue;
            else if(ch == '-' && !isInitialized) isNegative = true;
            else if(ch == '+' && !isInitialized) isNegative = false;
            else if(isdigit(ch)) {
                int digit = ch - '0';
                if (isNegative && res > (INT32_MAX - digit)/10) return INT32_MIN;
                if (!isNegative && res > (INT32_MAX - digit)/10) return INT32_MAX;
                res = res * 10 + digit;
            } else break;
            isInitialized = true;
        }

        if (isNegative) res *= -1;
        return res;
    }
};

int main() {
    Solution sol;

    assert(sol.myAtoi("42") == 42);
    assert(sol.myAtoi("   -042") == -42);
    assert(sol.myAtoi("1337c0d3") == 1337);
    assert(sol.myAtoi("0-1") == 0);
    assert(sol.myAtoi("words and 987") == 0);
    assert(sol.myAtoi("2147483647") == INT32_MAX);
    assert(sol.myAtoi("2147483648") == INT32_MAX);
    assert(sol.myAtoi("-2147483648") == INT32_MIN);
    assert(sol.myAtoi("-2147483649") == INT32_MIN);
    cout << "solution has passed all of the defined testcases"; 

    return 0;
}