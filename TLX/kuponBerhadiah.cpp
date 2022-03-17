#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, x;
	int check, minCheck, dist, minDist = INT_MAX;

	cin >> t;
	cin >> x;
	while(t--) {
		cin >> check;
		
		dist = abs(check - x);
		if(dist < minDist){
			minDist = dist;
			minCheck = check;
		} 
	}
	
	cout << minCheck << '\n';

	return 0;
}