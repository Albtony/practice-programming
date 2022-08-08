// https://codeforces.com/problemset/problem/1709/B

/*
You are beta testing the new secret Terraria update. This update will add quests to the game!
Simply, the world map can be represented as an array of length n, where the i-th column of the world has height ai.
There are m quests you have to test. The j-th of them is represented by two integers sj and tj. In this quest, you have to go from the 
column sj to the column tj. At the start of the quest, you are appearing at the column sj.
In one move, you can go from the column x to the column x−1 or to the column x+1. In this version, you have Spectre Boots, which allow 
you to fly. Since it is a beta version, they are bugged, so they only allow you to fly when you are going up and have infinite fly 
duration. When you are moving from the column with the height p to the column with the height q, then you get some amount of fall damage. If the height p is greater than the height q, you get p−q fall damage, otherwise you fly up and get 0 damage.
For each of the given quests, determine the minimum amount of fall damage you can get during this quest.
*/

/*
Input
The first line of the input contains two integers n and m (2≤n≤105;1≤m≤105) — the number of columns in the world and the number of 
quests you have to test, respectively.
The second line of the input contains n integers a1,a2,…,an (1≤ai≤109), where ai is the height of the i-th column of the world.
The next m lines describe quests. The j-th of them contains two integers sj and tj (1≤sj,tj≤n;sj≠tj), which means you have to move 
from the column sj to the column tj during the j-th quest.
Note that sj can be greater than tj.

Output
Print m integers. The j-th of them should be the minimum amount of fall damage you can get during the j-th quest completion.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n, m;
    cin >> n >> m;

    ll h[n], prev, curr, lf, rg, l[n] = {0}, r[n] = {0};

    cin >> prev;

    for(int i = 1; i < n; i++){
        cin >> curr;
        lf = max(0, int(prev - curr));    
        rg = max(0, int(curr - prev));

        l[i] = l[i-1] + lf;
        r[i] = r[i-1] + rg;
        
        prev = curr;
    } 

    while(m--) {
        ll s, t;
        cin >> s >> t;
        if(s < t) cout << l[t-1] - l[s-1] << '\n';
        else cout << r[s-1] - r[t-1] << '\n';
    }   
}