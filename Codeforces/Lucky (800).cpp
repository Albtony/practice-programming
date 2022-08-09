// https://codeforces.com/problemset/problem/1676/A

/*
A ticket is a string consisting of six digits. A ticket is considered lucky if the sum of the first three digits is equal 
to the sum of the last three digits. Given a ticket, output if it is lucky or not. Note that a ticket can have leading zeroes.
*/

/*
Input
The first line of the input contains an integer t (1≤t≤103) — the number of testcases.
The description of each test consists of one line containing one string consisting of six digits.

Output
Output t lines, each of which contains the answer to the corresponding test case. Output "YES" if the given ticket is lucky, and 
"NO" otherwise.
You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer)
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--) {
        string num;
        ll sum1, sum2;
        cin >> num;

        sum1 = (num[0] - '0') + (num[1] - '0') + (num[2] - '0');
        sum2 = (num[3] - '0') + (num[4] - '0') + (num[5] - '0');

        if(sum1 == sum2) cout << "YES\n";
        else cout << "NO\n";
    }
}