// https://codeforces.com/contest/1714/problem/C

/*
Find the minimum number with the given sum of digits s such that all digits in it are distinct (i.e. all digits are unique).
For example, if s=20, then the answer is 389. This is the minimum number in which all digits are different and the sum of the digits 
is 20 (3+8+9=20).

For the given s print the required number.
*/


/*
INPUT
The first line contains an integer t (1≤t≤45) — the number of test cases.
Each test case is specified by a line that contains the only integer s (1≤s≤45).

OUTPUT
Print t integers — the answers to the given test cases.
*/

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int arr[9] = {0};
        int s;
        cin >> s;

        for(int i = 9; i >= 1; i--) {
            if(s - i >= 0) {
                s -= i;
                arr[i-1] = 1;
            }
        }

        for(int i = 0; i < 9; i++) 
            if(arr[i])
                cout << i+1;
        cout << '\n';
    }

    return 0;
}