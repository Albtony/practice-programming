// https://codeforces.com/contest/1714/problem/A

/*
Vlad, like everyone else, loves to sleep very much.
Every day Vlad has to do n things, each at a certain time. For each of these things, he has an alarm clock set, the i-th of them is 
triggered on hi hours mi minutes every day (0≤hi<24,0≤mi<60). Vlad uses the 24-hour time format, so after h=12,m=59 comes h=13,m=0 and 
after h=23,m=59 comes h=0,m=0.

This time Vlad went to bed at H hours M minutes (0≤H<24,0≤M<60) and asks you to answer: how much he will be able to sleep until the 
next alarm clock.

If any alarm clock rings at the time when he went to bed, then he will sleep for a period of time of length 0.
*/

/*
INPUT
The first line of input data contains an integer t (1≤t≤100) — the number of test cases in the test.
The first line of the case contains three integers n, H and M (1≤n≤10,0≤H<24,0≤M<60) — the number of alarms and the time Vlad went to 
bed.
The following n lines contain two numbers each hi and mi (0≤hi<24,0≤mi<60) — the time of the i alarm. It is acceptable that two or more 
alarms will trigger at the same time.
Numbers describing time do not contain leading zeros.

OUTPUT 
Output t lines, each containing the answer to the corresponding test case. As an answer, output two numbers  — the number of hours and 
minutes that Vlad will sleep, respectively. If any alarm clock rings at the time when he went to bed, the answer will be 0 0.
*/

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n, h, m, hmin = 25, mmin = 61;
        cin >> n;
        cin >> h >> m;
        for(int i = 0; i < n; i++) {
            int ha, ma, hs, ms;
            cin >> ha >> ma;

            hs = ha - h;
            ms = ma - m;

            if(ms < 0) {
                hs--;
                ms += 60;
            }
            if(hs < 0) hs += 24;

            if(hs < hmin || (hs == hmin && ms <= mmin)) {
                hmin = hs;
                mmin = ms;
            }
        }

        cout << hmin << ' ' << mmin << '\n';
    }

    return 0;
}