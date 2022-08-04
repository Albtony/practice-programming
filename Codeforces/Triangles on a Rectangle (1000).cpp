// Codeforces

/*
A rectangle with its opposite corners in (0,0) and (w,h) and sides parallel to the axes is drawn on a plane.

You are given a list of lattice points such that each point lies on a side of a rectangle but not in its corner. Also, there are at 
least two points on every side of a rectangle.

Your task is to choose three points in such a way that:

exactly two of them belong to the same side of a rectangle;
the area of a triangle formed by them is maximum possible.
Print the doubled area of this triangle. It can be shown that the doubled area of any triangle formed by lattice points is always an 
integer.
*/

/*
Input
The first line contains a single integer t (1≤t≤104) — the number of testcases.
The first line of each testcase contains two integers w and h (3≤w,h≤106) — the coordinates of the corner of a rectangle.

The next two lines contain the description of the points on two horizontal sides. First, an integer k (2≤k≤2⋅105) — the number of points. 
Then, k integers x1<x2<⋯<xk (0<xi<w) — the x coordinates of the points in the ascending order. The y coordinate for the first line is 0 
and for the second line is h.

The next two lines contain the description of the points on two vertical sides. First, an integer k (2≤k≤2⋅105) — the number of points. 
Then, k integers y1<y2<⋯<yk (0<yi<h) — the y coordinates of the points in the ascending order. The x coordinate for the first line is 0 
and for the second line is w.

The total number of points on all sides in all testcases doesn't exceed 2⋅105.

Output
For each testcase print a single integer — the doubled maximum area of a triangle formed by such three points that exactly two of 
them belong to the same side.
*/

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        ull w, h;
        cin >> w >> h;
        ull maxSide[2] = {0}, side, area, pos;
        for(int i = 0; i < 4; i++) {
            ull n, maxDiff, num;
            cin >> n;
            for(ull j = 0; j < n; j++) {
                cin >> num;
                if(j == 0) maxDiff = num * -1;
                if(j == n-1) maxDiff += num;
            }

            if(i <= 1) pos = 0;
            else pos = 1;

            if(maxDiff > maxSide[pos]) maxSide[pos] = maxDiff;
        }  
        
        area = max(maxSide[0] * h, maxSide[1] * w);
        cout << area << '\n';
    }
    return 0;
}