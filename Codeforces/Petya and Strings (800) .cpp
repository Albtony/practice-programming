// Source : Codeforces

/*
Little Petya loves presents. His mum bought him two strings of the same size for his birthday. The strings consist of 
uppercase and lowercase Latin letters. Now Petya wants to compare those two strings lexicographically. The letters' 
case does not matter, that is an uppercase letter is considered equivalent to the corresponding lowercase letter. Help 
Petya perform the comparison.
*/

/*
Input
Each of the first two lines contains a bought string. The strings' lengths range from 1 to 100 inclusive. It is 
guaranteed that the strings are of the same length and also consist of uppercase and lowercase Latin letters.

Output
If the first string is less than the second one, print "-1". If the second string is less than the first one, 
print "1". If the strings are equal, print "0". Note that the letters' case is not taken into consideration when 
the strings are compared.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    string str1, str2;
    int res;
    cin >> str1;
    cin >> str2;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    res = str1.compare(str2);
    if(res > 0)
        cout << "1";
    else if(res < 0)
        cout << "-1";
    else
        cout << "0";

    return 0;
}
