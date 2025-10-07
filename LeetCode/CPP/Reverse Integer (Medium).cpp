#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
        int reverse(int x) {
        if (x == INT32_MIN) return 0;
        int res = 0;
        int y = abs(x);
        while(y > 0) {
            int digit = y % 10;
            y /= 10;
            if (res > (INT32_MAX - digit) / 10) return 0;
            res = res * 10 + digit;
        }

        if (x < 0) res *= -1;
        return res;
    }
};

int main() {
    Solution sol;

    assert(sol.reverse(123) == 321);
    assert(sol.reverse(321) == 123);
    assert(sol.reverse(-123) == -321);
    assert(sol.reverse(-321) == -123);
    assert(sol.reverse(2147483647) == 0);
    assert(sol.reverse(-2147483647) == 0);
    assert(sol.reverse(-2147483648) == 0);
    cout << "solution has passed all of the defined testcases";

    return 0;
}