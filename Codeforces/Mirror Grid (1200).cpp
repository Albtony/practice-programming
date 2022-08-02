// Source : Codeforces

/*
You are given a square grid with n rows and n columns. Each cell contains either 0 or 1.

In an operation, you can select a cell of the grid and flip it (from 0→1 or 1→0). Find the minimum number of operations you need to 
obtain a square that remains the same when rotated 0∘, 90∘, 180∘ and 270∘.

The picture below shows an example of all rotations of a grid.
*/

/*
Input
The first line contains a single integer t (1≤t≤100) — the number of test cases.

The first line of each test case contains a single integer n (1≤n≤100) — the size of the grid.

Then n lines follow, each with n characters ai,j (0≤ai,j≤1) — the number written in each cell.

Output
For each test case output a single integer  — the minimum number of operations needed to make the square look the same rotated 
0∘, 90∘, 180∘ and 270∘.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcases, gridSize, moveCount;
    cin >> testcases;
    while(testcases--) {
        cin >> gridSize;
        moveCount = 0;
        string input;
        int value, index, cellCount = ceil(gridSize/2.0) * (gridSize/2 + 1);
        int sameCount[cellCount] = {0};
        bool flag = true;

        if(gridSize & 1) {
            for(int i = 0; i < gridSize; i++) {
                cin >> input;
                for(int j = 0; j < gridSize; j++) {
                    if(j <= gridSize/2 && i < gridSize/2) index = j + i * (gridSize/2 + 1);                                             // Q1 + upper mid
                    else if(j > gridSize/2 && i <= gridSize/2) index = i + (gridSize - 1 - j) * (gridSize/2 + 1);                       // Q2 + right mid
                    else if(j >= gridSize/2 && i > gridSize/2) index = (gridSize - 1 - j) + (gridSize - 1 - i) * (gridSize/2 + 1);      // Q3 + bottom mid
                    else if(j < gridSize/2 && i >= gridSize/2) index = (gridSize - 1 -i) + j * (gridSize/2 + 1);                        // Q4 + left mid
                    else flag = false;                                                                                                  // dead center

                    value = input[j] - '0';
                    if(value == 1 && flag) sameCount[index]++;
                    else if (!flag) flag = true;
                }
            }
        } else {
            for(int i = 0; i < gridSize; i++) {
                cin >> input;
                for(int j = 0; j < gridSize; j++) {
                    if(j < gridSize/2 && i < gridSize/2) index = j + i * gridSize/2;                                                    // Q1
                    else if(j >= gridSize/2 && i < gridSize/2) index = i + (gridSize - 1 - j) * gridSize/2;                             // Q2
                    else if(j >= gridSize/2 && i >= gridSize/2) index = (gridSize - 1 - j) + (gridSize - 1 - i) * gridSize/2;           // Q3
                    else index = (gridSize - 1 -i) + j * gridSize/2;                                                                    // Q4

                    value = input[j] - '0';
                    if(value == 1) sameCount[index]++;
                }   
            }
        }

        for(int i = 0; i < cellCount; i++) moveCount += min(sameCount[i], 4-sameCount[i]);
        cout << moveCount << '\n';
    }

    return 0;
}
