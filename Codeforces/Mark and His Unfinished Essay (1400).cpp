// Source : Codeforces
// Note : still TLE on test #2

/*
One night, Mark realized that there is an essay due tomorrow. He hasn't written anything yet, so Mark decided to randomly copy-paste 
substrings from the prompt to make the essay.
More formally, the prompt is a string s of initial length n. Mark will perform the copy-pasting operation c times. Each operation is 
described by two integers l and r, which means that Mark will append letters slsl+1…sr to the end of string s. Note that the length 
of s increases after this operation.
Of course, Mark needs to be able to see what has been written. After copying, Mark will ask q queries: given an integer k, determine 
the k-th letter of the final string s.
*/

/*
Input
The first line contains a single integer t (1≤t≤1000) — the number of test cases.
The first line of each test case contains three integers n, c, and q (1≤n≤2⋅105, 1≤c≤40, and 1≤q≤104) — the length of the initial 
string s, the number of copy-pasting operations, and the number of queries, respectively.

The second line of each test case contains a single string s of length n. It is guaranteed that s only contains lowercase English 
letters.
The following c lines describe the copy-pasting operation. Each line contains two integers l and r (1≤l≤r≤1018). It is also guaranteed 
that r does not exceed the current length of s.

The last q lines of each test case describe the queries. Each line contains a single integer k (1≤k≤1018). It is also guaranteed that 
k does not exceed the final length of s.
It is guaranteed that the sum of n and q across all test cases does not exceed 2⋅105 and 104, respectively.

Output
For each query, print the k-th letter of the final string s.
*/

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while(t--) {
        int n, c, q;
        cin >> n >> c >> q;
        
        string input;
        cin >> input;
        
        int interval[2 + 2*c], indexDiff[1 + c];
        interval[0] = 1; indexDiff[0] = 0;
        interval[1] = n;
        for(int i = 2; i < 2 + 2*c; i +=2) {
            int head, tail;
            cin >> head >> tail;
            interval[i] = interval[i-1] + 1;
            interval[i+1] = interval[i] + tail - head;
            indexDiff[i/2] = interval[i] - head;
        }
 
        while(q--) {
            int index, i = 0;
            cin >> index;
            while(!(interval[0] <= index && index <= interval[1])){
                while(interval[i+1] < index && i <= (2+2*c)) i+=2;
                index -= indexDiff[i/2];
                i = 0;
            }
            cout << input[index-1] << '\n';
        }
    }
}