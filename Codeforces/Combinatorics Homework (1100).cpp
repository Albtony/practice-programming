// Codeforces

/*
You are given four integer values a, b, c and m.

Check if there exists a string that contains:

a letters 'A';
b letters 'B';
c letters 'C';
no other letters;
exactly m pairs of adjacent equal letters (exactly m such positions i that the i-th letter is equal to the (i+1)-th one).
*/

/*
Input
The first line contains a single integer t (1≤t≤104) — the number of testcases.

Each of the next t lines contains the description of the testcase — four integers a, b, c and m (1≤a,b,c≤108; 0≤m≤108).

Output
For each testcase print "YES" if there exists a string that satisfies all the requirements. Print "NO" if there 
are no such strings.

You may print every letter in any case you want (so, for example, the strings yEs, yes, Yes and YES will all be 
recognized as positive answer).
*/

#include <bits/stdc++.h>
using namespace std;

int findMaxBelow(int arr[], int cap){
    int max;
    max = 0;
    for(int i = 0; i < 3; i++){
        if(arr[i] > max && arr[i] < cap)
            max = arr[i];
    }
    return max;
}

int findValue(int arr[], int value){
    for(int i = 0; i < 3; i++)
        if(value == arr[i])
            return i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ntestcase, na, nb, nc, pair, separator, minpair, maxpair;
    cin >> ntestcase;

    while(ntestcase--){
        cin >> na >> nb >> nc >> pair;
        separator = na + nb + nc - max(na, max(nb, nc));
        minpair = na + nb + nc -1 - separator * 2;
        maxpair = na - 1 + nb - 1 + nc - 1;
        if(minpair <= pair && pair <= maxpair)
            cout << "YES\n";
        else
            cout << "NO\n";
    }   
    return 0;
}

/*
Credit to Tourist
I was stuck on this problem and decided to see his code and analyze it instead
his solution is infinitely better than my almost 100-line solution lmao

so in this problem
the constraint that controls the output is "pair"

so to do this, we can decide the output based if pair is in range of maxpair and minpair given how many a, b, and c's available.

maxpair = na - 1 + nb -1 + nc - 1
reason :
we can make maximum n - 1 pair given n characters, which look like 
 5 a's -> aaaaa -> (1,2) (2,3) (3,4) (3,5) -> 4 pairs
so with j number of a, k number of b, and l number of c we can make a total of
j - 1 + k - 1 + l - 1 pairs

minpair = minpair = na + nb + nc - 1 - separator * 2
reason :
we can make 0 pair if we have a lot of separator
we are forced to make pair if we are low of separator

we are separating the highest number of char
hence separator = char1 + char2 + char3 - charmax()

n char can be separated by n - 1 of other distinct char, which look like
 5 c's -> c * c * c * c * c -> 4 *'s -> 4 separator
so with n number of (maxchar) we need n - 1 number of separator

let a and b be separator
let c be maxchar

max pair    = a + b + c - 1 - 2*(a + b)
            = c - a - b - 1

or in separator kind of sense 
 c - a - b - 1 = 0
 c = a + b - 1
 n max char = n separator

given c max char, we need a + b - 1 of separator to be able to freely place our char
or else, we are forced to make a pair

 6 c's and 4 separator 
 c * c * c * c * c
 c -> this lucky guy is gonna make a pair

PS : sorry for bad englesh and explanation :P
*/