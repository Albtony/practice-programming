// Source : Codeforces

/*
You are given a string s, consisting only of Latin letters 'a', and a string t, consisting of lowercase Latin letters.
In one move, you can replace any letter 'a' in the string s with a string t. Note that after the replacement string s might contain 
letters other than 'a'.

You can perform an arbitrary number of moves (including zero). How many different strings can you obtain? Print the number, or report 
that it is infinitely large.
Two strings are considered different if they have different length, or they differ at some index.
*/

/*
Input
The first line contains a single integer q (1≤q≤104) — the number of testcases.
The first line of each testcase contains a non-empty string s, consisting only of Latin letters 'a'. The length of s doesn't exceed 50.
The second line contains a non-empty string t, consisting of lowercase Latin letters. The length of t doesn't exceed 50.

Output
For each testcase, print the number of different strings s that can be obtained after an arbitrary amount of moves (including zero). 
If the number is infinitely large, print -1. Otherwise, print the number.
*/

#include <bits/stdc++.h>
using namespace std;

unsigned long long combinatorial(int n, int k){
    long double res = 1;
    int multiplier, divider;
    vector<int> num, denom;
 
    for(int i = n-k + 1; i <= n; i++) num.push_back(i);
    for(int i = 1; i <= k; i++) denom.push_back(i);
 
    while(!num.empty()) {
        multiplier = num.back();
        divider = denom.back();
        num.pop_back(); denom.pop_back();
 
        res *= multiplier;
        if(res >= divider) res /= divider;
    }
    
    return round(res);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        string init;
        string replacement;
        unsigned long long sum = 0;
        
        cin >> init;
        cin >> replacement;

        if (replacement.find('a') != string::npos)
            if(replacement.length() == 1) cout << "1\n";
            else cout << "-1\n";
        else {
            for(int i = 0; i < init.length(); i++){
                sum += combinatorial(init.length(), i+1);
            }
            cout << sum + 1 << '\n';
        }
    }
}