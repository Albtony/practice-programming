// Codeforces

/*
You're given a row with n chairs. We call a seating of people "maximal" if the two following conditions hold:

There are no neighbors adjacent to anyone seated.
It's impossible to seat one more person without violating the first rule.
The seating is given as a string consisting of zeros and ones (0 means that the corresponding seat is empty, 1 — occupied). 
The goal is to determine whether this seating is "maximal".

Note that the first and last seats are not adjacent (if n≠2).
*/

/*
Input
The first line contains a single integer n (1≤n≤1000) — the number of chairs.
The next line contains a string of n characters, each of them is either zero or one, describing the seating.

Output
Output "Yes" (without quotation marks) if the seating is "maximal". Otherwise print "No".
You are allowed to print letters in whatever case you'd like (uppercase or lowercase).
*/

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, curr, streak1 = 0, streak0 = 0;
    string input;
    bool max = true;
    cin >> n;
    cin >> input;
    for(int i = 0; i < n; i++) {
        curr = input[i] - '0';
        if(curr == 1){
            streak1++;
            streak0 = 0;
        } else if(curr == 0) {
            streak0++;
            streak1 = 0;
        }

        if(streak1 >= 2) max = false;
        else if(streak0 == 2 && (i == 1 || i == n-1)) max = false;
        else if(streak0 == 3) max = false;
    }

    if(n == 1 && input[0] - '0' == 0) max = false;

    if(max) cout << "Yes\n";
    else cout << "No\n";
}