// Codeforces

/*
Theofanis has a riddle for you and if you manage to solve it, he will give you a Cypriot snack halloumi for free (Cypriot cheese).

You are given an integer n. You need to find two integers l and r such that −1018≤l<r≤1018 and l+(l+1)+…+(r−1)+r=n.
*/

/*
Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

The first and only line of each test case contains a single integer n (1≤n≤1018).

Output
For each test case, print the two integers l and r such that −1018≤l<r≤1018 and l+(l+1)+…+(r−1)+r=n.

It can be proven that an answer always exists. If there are multiple answers, print any.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long ntestcase, elem;
    cin >> ntestcase;
    for(int i = 0; i < ntestcase; i++){
        cin >> elem;
        cout << fixed << (elem-1)*-1 << ' ' << elem << "\n";
    }
    return 0;
}

/*
p = q + (-q) + p
q = (a + a+1 + a+2 + ... + a+n)
q = -(a + a+1 + a+2 + ... + a+n)
p = q + 1
*/