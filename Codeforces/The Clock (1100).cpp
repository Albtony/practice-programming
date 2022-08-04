// Codeforces

/*
Victor has a 24-hour clock that shows the time in the format "HH:MM" (00 ≤ HH ≤ 23, 00 ≤ MM ≤ 59). He looks at the clock every x minutes, 
and the clock is currently showing time s.
How many different palindromes will Victor see in total after looking at the clock every x minutes, the first time being at time s?
For example, if the clock starts out as 03:12 and Victor looks at the clock every 360 minutes (i.e. every 6 hours), then he will see 
the times 03:12, 09:12, 15:12, 21:12, 03:12, and the times will continue to repeat. Here the time 21:12 is the only palindrome he will 
ever see, so the answer is 1.
A palindrome is a string that reads the same backward as forward. For example, the times 12:21, 05:50, 11:11 are palindromes but 13:13, 
22:10, 02:22 are not.
*/

/*
Input
The first line of the input contains an integer t (1≤t≤100) — the number of test cases. The description of each test case follows.
The only line of each test case contains a string s of length 5 with the format "HH:MM" where "HH" is from "00" to "23" and "MM" is 
from "00" to "59" (both "HH" and "MM" have exactly two digits) and an integer x (1≤x≤1440) — the number of minutes Victor takes to 
look again at the clock.

Output
For each test case, output a single integer — the number of different palindromes Victor will see if he looks at the clock every x 
minutes starting from time s.
*/

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

class Clock {
    public:
        int hour;
        int min;

        Clock(int h, int m) {
            hour = h;
            min = m;
        }

        void setHour(int h) {hour = h;}
        void setMin(int m) {min = m;}
        int getHour() {return hour;}
        int getMin() {return min;}

        void addMin(int m) {
            min += m;
            hour += (min/60);
            min %= 60;
            hour %= 24;
        }

        void printClock() {
            string h = to_string(hour); 
            string m = to_string(min);

            if(hour < 10) h = '0' + h;
            if(min < 10) m = '0' + m;

            cout << h << ':' << m << '\n';
        }
};

bool isPalindrome(int hour, int min) {
    string h = to_string(hour); 
    string m = to_string(min);

    if(hour < 10) h = '0' + h;
    if(min < 10) m = '0' + m;

    return (h[0] == m[1] && h[1] == m[0]) ? true : false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        string input;
        cin >> input;
        int hour = ((input[0] - '0')) * 10 + (input[1] - '0');
        int min = ((input[3] - '0')) * 10 + (input[4] - '0');
        Clock clocky(hour, min);

        int min_offset, curr_hour = -1, curr_min = -1, palindromeCount = 0; 
        cin >> min_offset;

        if(isPalindrome(hour, min)) palindromeCount++;
        while(!(curr_hour == hour && curr_min == min)) {
            if(isPalindrome(curr_hour, curr_min)) palindromeCount++;
            clocky.addMin(min_offset);
            curr_hour = clocky.getHour();
            curr_min = clocky.getMin();
        }

        cout << palindromeCount << '\n';
    }
}
