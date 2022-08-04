// Codeforces

/*
Shubham has an array a of size n, and wants to select exactly x elements from it, such that their sum is odd. These elements do not 
have to be consecutive. The elements of the array are not guaranteed to be distinct. Tell him whether he can do so.
*/

/*
Input
The first line of the input contains a single integer t (1≤t≤100) — the number of test cases. The description of the test 
cases follows.
The first line of each test case contains two integers n and x (1≤x≤n≤1000) — the length of the array and the number of elements 
you need to choose.
The next line of each test case contains n integers a1,a2,…,an (1≤ai≤1000) — elements of the array.

Output
For each test case, print "Yes" or "No" depending on whether it is possible to choose x elements such that their sum is odd.
You may print every letter in any case you want.
*/

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while(t--) {
        int n, m, num, oddCount = 0, evenCount = 0;
        cin >> n >> m;
        while(n--) {
            cin >> num;
            if(num & 1 == 1) oddCount++;
            else evenCount++;
        } 
 
        if(evenCount < m){
            m -= evenCount;
            if(m%2 == 0 && evenCount > 0) m++;
            if(m%2 == 1 && oddCount >= m) cout << "Yes\n";
            else cout << "No\n";
        } else {
            if(oddCount > 0) cout << "Yes\n";
            else cout << "No\n";
        }
    }   
}