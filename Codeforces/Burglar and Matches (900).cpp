// Source : Codeforces

/*
A burglar got into a matches warehouse and wants to steal as many matches as possible. In the warehouse there are m containers, 
in the i-th container there are ai matchboxes, and each matchbox contains bi matches. All the matchboxes are of the same size. 
The burglar's rucksack can hold n matchboxes exactly. Your task is to find out the maximum amount of matches that a burglar can 
carry away. He has no time to rearrange matches in the matchboxes, that's why he just chooses not more than n matchboxes so that 
the total amount of matches in them is maximal.
*/

/*
Input
The first line of the input contains integer n (1 ≤ n ≤ 2·108) and integer m (1 ≤ m ≤ 20). The i + 1-th line contains a pair of 
numbers ai and bi (1 ≤ ai ≤ 108, 1 ≤ bi ≤ 10). All the input numbers are integer.

Output
Output the only number — answer to the problem.
*/

#include <bits/stdc++.h>
using namespace std;

struct container{
    int nMatchbox;
    int nMatch;
};

bool compareContainer(container c1, container c2){
    return c1.nMatch > c2.nMatch;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long bagLimit, emptyBag, nContainer, currMatch, maxMatch;
    cin >> bagLimit >> nContainer;

    container matchContainer[nContainer];

    for(int i = 0; i < nContainer; i++)
        cin >> matchContainer[i].nMatchbox >> matchContainer[i].nMatch;
    sort(matchContainer, matchContainer + nContainer, compareContainer);

    maxMatch = 0;
    emptyBag = bagLimit;

    for(int i = 0; i < nContainer; i++){
        if(matchContainer[i].nMatchbox >= emptyBag){
            maxMatch += matchContainer[i].nMatch * emptyBag;
            emptyBag = 0;
            break;
        }else if(emptyBag > 0){
            emptyBag -= matchContainer[i].nMatchbox;
            maxMatch += matchContainer[i].nMatch * matchContainer[i].nMatchbox;
        }else
            break;
    }
    
    cout << maxMatch;   
    return 0;
}