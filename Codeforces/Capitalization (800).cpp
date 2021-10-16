// Source : Codeforces

/*
Capitalization is writing a word with its first letter as a capital letter. Your task is to capitalize the given word.

Note, that during capitalization all the letters except the first one remains unchanged.
*/

/*
Input
A single line contains a non-empty word. This word consists of lowercase and uppercase English letters. 
The length of the word will not exceed 103.

Output
Output the given word after capitalization.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    str[0] =  toupper(str[0]);
    cout << str;
    return 0;
}