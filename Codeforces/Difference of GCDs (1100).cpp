// Source : Codeforces

/*
You are given three integers n, l, and r. You need to construct an array a1,a2,…,an (l≤ai≤r) such that gcd(i,ai) are all distinct or 
report there's no solution.

Here gcd(x,y) denotes the greatest common divisor (GCD) of integers x and y.
*/

/*
Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤10**4) — the number of test cases. 
The description of the test cases follows.

The first line contains three integers n, l, r (1≤n≤10**5, 1≤l≤r≤10**9).

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
For each test case, if there is no solution, print "NO" (without quotes). You can print letters in any case (upper or lower).

Otherwise, print "YES" (without quotes). In the next line, print n integers a1,a2,…,an — the array you construct.

If there are multiple solutions, you may output any.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long t, n, l, r;
    float bottleneck, mult;
    bool flag;

    cin >> t;
    while(t--){
        cin >> n;
        cin >> l;
        cin >> r;
        bottleneck = r - l + 1;
        flag = true;

        for(float i = bottleneck; i <= n; i++){
            mult = ceil(l / i);
            if(mult * i > r){
                cout << "NO\n";
                flag = false;
                break;
            }
        }

        if(flag){
            cout << "YES\n";
            for(float i = 1; i <= n; i++){
                mult = ceil(l / i);
                cout << long(mult * i) << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
