// Source : Codeforces

/*
Theofanis really likes sequences of positive integers, thus his teacher (Yeltsa Kcir) gave him a problem about a sequence 
that consists of only special numbers.

Let's call a positive number special if it can be written as a sum of different non-negative powers of n. For example, for 
n=4 number 17 is special, because it can be written as 40+42=1+16=17, but 9 is not.

Theofanis asks you to help him find the k-th special number if they are sorted in increasing order. Since this number may 
be too large, output it modulo 109+7.
*/

/*
Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

The first and only line of each test case contains two integers n and k (2≤n≤109; 1≤k≤109).

Output
For each test case, print one integer — the k-th special number in increasing order modulo 109+7.
*/

#include <bits/stdc++.h>
using namespace std;

void toBinary(int num, int arr[]){
    for(int i = 0; num > 0; i++){    
        arr[i] = num % 2;    
        num = num / 2;  
    }    
}

unsigned long long longpow(int base, int pow){
    unsigned long long value = 1;
    for(int i = 0; i < pow; i++){
        value *= base;
    }
    return value;
}

unsigned long long assembler(int base, int arr[], int size){
    unsigned long long value = 0;
    for(int i = 0; i < size; i++){
        value += (arr[i] * longpow(base, i)) % 1000000007;
        // cout << "mult = "<< (arr[i] * longpow(base, i)) % 1000000007 << endl;
        value %= 1000000007;
        // cout << "value = "<< value << endl;
    }
    
    return value % 1000000007;
}

int main() {
    unsigned long long ntestcase, base, kth, result;
    cin >> ntestcase;

    for(int i = 0; i < ntestcase; i++){
        cin >> base;
        cin >> kth;

        int size = log2(kth) + 1;
        int power[size];
        // cout << "im here" << endl;

        toBinary(kth, power);

        // for(int i = 0; i < size; i++)
        //     cout << power[i] << ' ';
        // cout << endl;

        result = assembler(base, power, size);
        cout << result << endl;
    }
}