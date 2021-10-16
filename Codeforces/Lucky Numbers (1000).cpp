// Source : Codeforces

/*
Petya loves lucky numbers. Everybody knows that lucky numbers are positive integers whose decimal representation contains 
only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Petya calls a number almost lucky if it could be evenly divided by some lucky number. Help him find out if the given number 
n is almost lucky.
*/

/*
Input
The single line contains an integer n (1 ≤ n ≤ 1000) — the number that needs to be checked.

Output
In the only line print "YES" (without the quotes), if number n is almost lucky. Otherwise, print "NO" (without the quotes).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int num, numLen, isLucky, arrSize;
    int luckyDivider[] = {4, 7, 47, 74, 447, 474, 477};  //shameless code huehue
    string strNum;
    cin >> num;

    isLucky = 0;
    arrSize = sizeof(luckyDivider)/sizeof(luckyDivider[0]);

    for(int i = 0; i < arrSize; i++){
        if(num % luckyDivider[i] == 0){
            cout << "YES";
            return 0;
        }
    }
        
    strNum = to_string(num);
    numLen = strNum.length();

    for(int i = 0; i < numLen; i++){
        if(strNum[i] == '4')
            isLucky++;
    }
    
    for(int i = 0; i < numLen; i++){
        if(strNum[i] == '7')
            isLucky++;
    }

    if(isLucky == numLen)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}