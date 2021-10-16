// Source : Codeforces

/*
After the lessons n groups of schoolchildren went outside and decided to visit Polycarpus to celebrate his birthday. 
We know that the i-th group consists of si friends (1 ≤ si ≤ 4), and they want to go to Polycarpus together. They 
decided to get there by taxi. Each car can carry at most four passengers. What minimum number of cars will the children 
need if all members of each group should ride in the same taxi (but one taxi can take more than one group)?
*/

/*
Input
The first line contains integer n (1 ≤ n ≤ 105) — the number of groups of schoolchildren. The second line contains a 
sequence of integers s1, s2, ..., sn (1 ≤ si ≤ 4). The integers are separated by a space, si is the number of children 
in the i-th group.

Output
Print the single number — the minimum number of taxis necessary to drive all children to Polycarpus.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int totGroup, size, totTaxi, groupSize[4] = {0, 0, 0, 0};
    cin >> totGroup;

    
    for(int i = 0; i < totGroup; i++){
        cin >> size;
        groupSize[size-1]++;
    }
    
    totTaxi += groupSize[3];
    totTaxi += groupSize[2];

    if(groupSize[0] >= groupSize[2])
        groupSize[0] -= groupSize[2];
    else
        groupSize[0] = 0;
        
    totTaxi += groupSize[1] / 2;
    groupSize[1] %= 2;
    totTaxi += groupSize[0] / 4;
    groupSize[0] %= 4;
    
    if(groupSize[1] % 2 > 0){
        totTaxi++;
        groupSize[0] -= 2;
    }
    
    if(groupSize[0] > 0)
        totTaxi++;
    
    cout << totTaxi;
    
    return 0;
}