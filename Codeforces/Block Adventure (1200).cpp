// Codeforces

/*
Gildong is playing a video game called Block Adventure. In Block Adventure, there are n columns of blocks in a row, and the columns are 
numbered from 1 to n. All blocks have equal heights. The height of the i-th column is represented as hi, which is the number of blocks 
stacked in the i-th column.

Gildong plays the game as a character that can stand only on the top of the columns. At the beginning, the character is standing on the 
top of the 1-st column. The goal of the game is to move the character to the top of the n-th column.

The character also has a bag that can hold infinitely many blocks. When the character is on the top of the i-th column, Gildong can take 
one of the following three actions as many times as he wants:

if there is at least one block on the column, remove one block from the top of the i-th column and put it in the bag;
if there is at least one block in the bag, take one block out of the bag and place it on the top of the i-th column;
if i<n and |hi−hi+1|≤k, move the character to the top of the i+1-st column. k is a non-negative integer given at the beginning of the 
game. Note that it is only possible to move to the next column.
In actions of the first two types the character remains in the i-th column, and the value hi changes.

The character initially has m blocks in the bag. Gildong wants to know if it is possible to win the game. Help Gildong find the answer 
to his
*/

/*
INPUT
Each test contains one or more test cases. The first line contains the number of test cases t (1≤t≤1000). Description of the test 
cases follows.
The first line of each test case contains three integers n, m, and k (1≤n≤100, 0≤m≤106, 0≤k≤106) — the number of columns in the game, 
the number of blocks in the character's bag at the beginning, and the non-negative integer k described in the statement.
The second line of each test case contains n integers. The i-th integer is hi (0≤hi≤106), the initial height of the 
i-th column.

OUTPUT
For each test case, print "YES" if it is possible to win the game. Otherwise, print "NO".
You can print each letter in any case (upper or lower).
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
        ll n, m, k, prev, curr;
        bool flag = true;
        cin >> n >> m >> k;
        
        if(n > 0) {
            cin >> curr;            
            n--;
        }
 
        while(n--) {
            prev = curr;
            cin >> curr;
 
            int optPrev = curr - k;
            m += prev - max(0, optPrev); 
            if(m<0) flag = false;
        }
 
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}
