// Codeforces

/*
It is the easy version of the problem. The difference is that in this version, there are no nodes with already chosen colors.

Theofanis is starving, and he wants to eat his favorite food, sheftalia. However, he should first finish his homework. Can you help him 
with this problem?

You have a perfect binary tree of 2k−1 nodes — a binary tree where all vertices i from 1 to 2k−1−1 have exactly two children: vertices 
2i and 2i+1. Vertices from 2k−1 to 2k−1 don't have any children. You want to color its vertices with the 6 Rubik's cube colors (White, 
Green, Red, Blue, Orange and Yellow).

Let's call a coloring good when all edges connect nodes with colors that are neighboring sides in the Rubik's cube.
More formally:
a white node can not be neighboring with white and yellow nodes;
a yellow node can not be neighboring with white and yellow nodes;
a green node can not be neighboring with green and blue nodes;
a blue node can not be neighboring with green and blue nodes;
a red node can not be neighboring with red and orange nodes;
an orange node can not be neighboring with red and orange nodes;
You want to calculate the number of the good colorings of the binary tree. Two colorings are considered different if at least one node 
is colored with a different color.

The answer may be too large, so output the answer modulo 109+7.
*/

/*
Input
The first and only line contains the integers k (1≤k≤60) — the number of levels in the perfect binary tree you need to color.

Output
Print one integer — the number of the different colorings modulo 109+7.
*/

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull modExp(ull base, ull pow, ull mod) {
    if(pow == 0) {
        return 1;
    } else if (pow%2 == 0) {
        ull res = modExp(base, pow/2, mod);
        return (res * res) % mod;
    } else {
        return ((base % mod) * modExp(base, pow-1, mod)) % mod;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull k, totNode, res, mod;

    cin >> k;
    totNode = pow(2, k)-2;
    mod = pow(10, 9) + 7;
    res = modExp(4, totNode, mod);
    cout << (res * 6) % mod;
}