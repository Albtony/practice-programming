// https://codeforces.com/contest/1713/problem/A

/*
You are living on an infinite plane with the Cartesian coordinate system on it. In one move you can go to any of the four adjacent 
points (left, right, up, down).

More formally, if you are standing at the point (x,y), you can:

go left, and move to (x−1,y), or
go right, and move to (x+1,y), or
go up, and move to (x,y+1), or
go down, and move to (x,y−1).

There are n boxes on this plane. The i-th box has coordinates (xi,yi). It is guaranteed that the boxes are either on the x-axis or 
the y-axis. That is, either xi=0 or yi=0.
You can collect a box if you and the box are at the same point. Find the minimum number of moves you have to perform to collect all 
of these boxes if you have to start and finish at the point (0,0).
*/

/*
Input
The first line contains a single integer t (1≤t≤100) — the number of test cases.\
The first line of each test case contains a single integer n (1≤n≤100) — the number of boxes.
The i-th line of the following n lines contains two integers xi and yi (−100≤xi,yi≤100) — the coordinate of the i-th box. It is 
guaranteed that either xi=0 or yi=0.
Do note that the sum of n over all test cases is not bounded.

Output
For each test case output a single integer — the minimum number of moves required.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) {
        ll n, currx, curry;
        cin >> n;
        ll x[n] = {0}, y[n] = {0};
        for(int i = 0; i < n; i++) {
            cin >> currx >> curry;
            x[i] = currx;
            y[i] = curry;
        }

        sort(x, x+n);
        sort(y, y+n);

        // cout << y[0] << y[n-1] << x[0] << x[n-1] << '\n';

        ll dist, ymax, ymin, xmax, xmin;
        if(y[0] * y[n-1] > 0) {
            ymax = max(abs(y[0]), abs(y[n-1]));
            ymin = 0;
        } else {
            ymax = y[n-1];
            ymin = y[0];
        }

        if(x[0] * x[n-1] > 0) {
            xmax = max(abs(x[0]), abs(x[n-1]));
            xmin = 0;
        } else {
            xmax = x[n-1];
            xmin = x[0];
        }

        dist = abs(xmax * 2) + abs(xmin * 2) + abs(ymin * 2) + abs(ymax * 2);
        if(n == 1) dist = abs(y[0] * 2) + abs(x[0] * 2);

        cout << dist << '\n';
    }

    return 0;
}