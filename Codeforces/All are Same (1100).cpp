// Codeforces

/*
This problem is a simplified version of D2, but it has significant differences, so read the whole statement.

Polycarp has an array of n (n is even) integers a1,a2,…,an. Polycarp conceived of a positive integer k. After that, Polycarp began 
\performing the following operations on the array: take an index i (1≤i≤n) and reduce the number ai by k.

After Polycarp performed some (possibly zero) number of such operations, it turned out that all numbers in the array became the 
same. Find the maximum k at which such a situation is possible, or print −1 if such a number can be arbitrarily large.
*/

/*
Input
The first line contains one integer t (1≤t≤10) — the number of test cases. Then t test cases follow.

Each test case consists of two lines. The first line contains an even integer n (4≤n≤40) (n is even). The second line contains 
n integers a1,a2,…an (−106≤ai≤106).

It is guaranteed that the sum of all n specified in the given test cases does not exceed 100.

Output
For each test case output on a separate line an integer k (k≥1) — the maximum possible number that Polycarp used in operations 
on the array, or −1, if such a number can be arbitrarily large.
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
// Function to find gcd of array of
// numbers
int findGCD(int arr[], int n){
    int result = arr[0];
    for (int i = 1; i < n; i++){
        result = gcd(arr[i], result);
 
        if(result == 1){
           return 1;
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ntestcase, result = 1, temp = 0;
    cin >> ntestcase;

    while(ntestcase--){
        int size;
        cin >> size;

        int num[size];
        for(int i = 0; i < size; i++)
            cin >> num[i];
        sort(num, num + size);

        for(int i = 1; i < size; i++)
            num[i] -= num[0];
        num[0] = 0;

        temp = findGCD(num, size);
        if(temp == 0){
            result = -1;
            cout << result << "\n";
        }else if(temp > result){
            result = temp;
            cout << result << "\n";
        }else
            cout << result << "\n";
            
        temp = result = 1;
    }
    return 0;
}