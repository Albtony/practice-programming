// Source : Codeforces

/*
Vanya walks late at night along a straight street of length l, lit by n lanterns. Consider the coordinate system with 
the beginning of the street corresponding to the point 0, and its end corresponding to the point l. Then the i-th 
lantern is at the point ai. The lantern lights all points of the street that are at the distance of at most d from it, 
where d is some positive number, common for all lanterns.

Vanya wonders: what is the minimum light radius d should the lanterns have to light the whole street?
*/

/*
Input
The first line contains two integers n, l (1 ≤ n ≤ 1000, 1 ≤ l ≤ 109) — the number of lanterns and the length of the 
street respectively.

The next line contains n integers ai (0 ≤ ai ≤ l). Multiple lanterns can be located at the same point. The lanterns may 
be located at the ends of the street.

Output
Print the minimum light radius d, needed to light the whole street. The answer will be considered correct if its absolute 
or relative error doesn't exceed 10 - 9.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long len, lampNum; 
    cin >> lampNum;
    cin >> len;

    double lampPos[lampNum], prevPos, currPos = DBL_MAX, dist[4] = {0, 0, 0, 0};
    for(int i = 0; i < lampNum; i++)
        cin >> lampPos[i];
    
    sort(lampPos, lampPos + lampNum);
    for(int i = 0; i < lampNum; i++){
        prevPos = currPos;
        currPos = lampPos[i];
        dist[0] = currPos - prevPos;
        if(dist[0] > dist[3])
            dist[3] = dist[0];
    }

    dist[0] /= 2.0;
    dist[1] = lampPos[0];
    dist[2] = len - lampPos[lampNum-1];
    dist[3] /= 2.0;

    sort(dist, dist + 4);
    cout.precision(20);
    cout << fixed << dist[3];

    return 0;
}