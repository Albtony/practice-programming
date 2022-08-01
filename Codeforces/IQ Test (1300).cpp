#include <bits/stdc++.h>
using namespace std;
#define ODD 1
#define EVEN 0

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num;
    int prev, curr, c, p;

    cin >> n;
    cin >> num;

    if (num & 1) prev = ODD;
    else prev = EVEN;

    for (int i = 2; i <= n; i++) {
        cin >> num;

        if(num & 1) curr = ODD;
        else curr = EVEN;

        if(i == 2){
            if(prev != curr) c = 1;
            else c = 0;
        }

        if(i == 3){
            if(prev != curr) p = 1;
            else p = 0;
        } 

        if(i == 3 && (p || c)) {
            if(c && p) cout << 2;
            else if(c) cout << 1;
            else if(p) cout << 3;
            
            exit(EXIT_SUCCESS);
        }

        if(i <= 3) prev = curr;
        else if(prev != curr) {
            cout << i;
            exit(EXIT_SUCCESS);
        }
    }

    cout << "c = " << c << '\n';
    cout << "p = " << p << '\n';
}