// https://codeforces.com/contest/1713/problem/B

/*
Consider an array a of n positive integers.
You may perform the following operation:
select two indices l and r (1≤l≤r≤n), then
decrease all elements al,al+1,…,ar by 1.
Let's call f(a) the minimum number of operations needed to change array a into an array of n zeros.
Determine if for all permutations† b of a, f(a)≤f(b) is true.
† An array b is a permutation of an array a if b consists of the elements of a in arbitrary order. For example, [4,2,3,4] is a 
permutation of [3,2,4,4] while [1,2,2] is not a permutation of [1,2,3].
*/

/*
Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.
The first line of each test case contains a single integer n (1≤n≤105) — the length of the array a.
The second line contains n integers a1,a2,…,an (1≤ai≤109) — description of the array a.
It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
For each test case, print "YES" (without quotes) if for all permutations b of a, f(a)≤f(b) is true, and "NO" (without quotes) otherwise.
You can output "YES" and "NO" in any case (for example, strings "yEs", "yes" and "Yes" will be recognized as a positive response).
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
        ll n;
        cin >> n;

        ll tp=0, curr, prev, up = 0, down = 0;
        bool currUp = false, currDown = false, pertamax = true;
        
        if(n > 0) {
            cin >> curr;
            n--;
        }
        while(n--) {
            prev = curr;
            cin >> curr;

            if(prev > curr && !currDown) {
                if(pertamax) {
                    pertamax = false;
                    tp++;
                } else down++;
                

                currDown = true;
                currUp = false;
            }

            if(prev < curr && !currUp) {
                pertamax = false;
                currUp = true;
                up++;
            }
        }

        if(currUp && up) {
            tp++;
            up -= 1;
        } 

        tp += max(down, up);

        if(tp > 1) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}