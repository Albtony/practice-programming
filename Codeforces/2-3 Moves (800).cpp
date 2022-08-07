// https://codeforces.com/contest/1716/problem/A

/*
You are standing at the point 0 on a coordinate line. Your goal is to reach the point n. In one minute, you can move by 2 or by 3 
to the left or to the right (i. e., if your current coordinate is x, it can become x−3, x−2, x+2 or x+3). Note that the new coordinate 
can become negative.

Your task is to find the minimum number of minutes required to get from the point 0 to the point n.
You have to answer t independent test cases.
*/

/*
Input
The first line of the input contains one integer t (1≤t≤104) — the number of test cases. Then t lines describing the test cases follow.
The i-th of these lines contains one integer n (1≤n≤109) — the goal of the i-th test case.

Output
For each test case, print one integer — the minimum number of minutes required to get from the point 0 to the point n for the 
corresponding test case.
*/

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; 
    while(t--) {
        int n, res = 0;
        cin >> n;

        res += n/3;
        if(n % 3 > 0) res++;
        if(n == 1) res = 2;

        cout << res << '\n';
    }

    return 0;
}