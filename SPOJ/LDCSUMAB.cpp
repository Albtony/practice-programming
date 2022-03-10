// LDCSUMAB - BRVT - Math Team Collection 2013
// source : https://www.spoj.com/problems/LDCSUMAB/

/**
 * Consider the sequence of all integers that can be represented as 2^m + 2^n for integers 0 <= m < n, in increasing order. Given a positive 
 * integer k, your task is to find m and n for the kth element of the sequence.
 * 
 * Input
 * The first line is an integer T (T <= 10) is the number of test cases. 
 * T lines follow each line contains one integer K is the math requirement. (k <= 10 ^ 9)
 * 
 * Output
 * For each test case in the two numbers m, n (m <n) is represented by the sequence number k.  
 */


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, k;

	cin >> t;
	while(t--) {
		int n, pow1, pow2;
		cin >> k;

		n = 0; 
		while(k > 0){
			n += 1;
			pow1 = n;
			k = k - n;
		}

		if(k == 0){
			pow2 = n - 1;
		} else {
			k += n;
			pow2 = k - 1;
		}

		printf("%d %d\n", pow2, pow1);
	}
	
	return 0;
}

/*
 Penjelasan :
 bilangan yang dapat direpresentasikan 2^m + 2^n -> dari kecil ke besar (3, 5, 6, etc)

 2^0 + 2^1 -> 3 (1 st)
 2^0 + 2^2 -> 5 (2 nd)
 2^1 + 2^2 -> 6 (3 rd)
 2^0 + 2^3 -> 9 (4 th)
 ...

 biar lebih gampang dilihat, m sama n ditukar dan ditampilkan sendiri
 1 0 -> 1 st
 2 0 -> 2 nd
 2 1 -> 3 rd
 3 0 -> 4 th
 3 1 -> 5 th
 3 2 -> 6 th 
 4 0 -> ...
 4 1
 4 2
 4 3
 ...

 kalo dilihat lagi:
 besar = 1, perulangan = 1
 besar = 2, perulangan = 2
 besar = n, perulangan = n

 jadi untuk nyari pangkat kth
 while k > 0, k = k - n, n++

 ketika k =< 0, besar = n

 untuk nyari kecil, bisa dilihat dari nilai k setelah keluar dari while loop
 if (k == 0) kecil = n - 1
 if (k < 0) {
	k = k + n -> nilai k dibalikin 1 iterasi sebelum keluar while loop
	kecil = k - 1
 }

 output
 kecil besar
 */