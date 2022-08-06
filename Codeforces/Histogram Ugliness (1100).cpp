// https://codeforces.com/problemset/problem/1534/B

/*
Little Dormi received a histogram with n bars of height a1,a2,…,an for Christmas. However, the more he played with his new histogram, 
the more he realized its imperfections, so today he wanted to modify it to his liking.

To modify the histogram, Little Dormi is able to perform the following operation an arbitrary number of times:

Select an index i (1≤i≤n) where ai>0, and assign ai:=ai−1.
Little Dormi defines the ugliness score of his histogram (after performing some number of operations) as the sum of the vertical length 
of its outline and the number of operations he performed on it. And to make the histogram as perfect as possible, he would like to 
minimize the ugliness score after modifying it with some number of operations.

However, as his histogram is very large, Little Dormi is having trouble minimizing the ugliness score, so as Little Dormi's older 
brother, help him find the minimal ugliness.
*/

/*
Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). 
Description of the test cases follows.
The first line of each test case contains a single integer n (1≤n≤4⋅105).
The second line of each test case contains n integers a1,a2,…,an (0≤ai≤109).
It is guaranteed that the sum of n over all test cases does not exceed 4⋅105.

Output
For each test case output one integer, the minimal ugliness Little Dormi can achieve with the histogram in that test case.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        ll bar[n], pointy = 0, score = 0, l, r;
    
        for(int i = 0; i < n; i++) cin >> bar[i];
        for(int i = 1; i < n-1; i++) {
            l = bar[i] - bar[i-1];
            r = bar[i] - bar[i+1];

            if(l > 0) score += l;
            if(r > 0) score += r;
            if(l > 0 && r > 0) pointy += min(l, r);
        }

        if(n == 1) pointy += bar[0];

        score += (bar[0] + bar[n-1]);
        score -= pointy;
        cout << score << '\n';
    }

    return 0;
}