#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // we take advantage of bitset to convert int to bitset
    // then convert bitset to string and use reverse to reverse the bit
    // cast it back to string and then to long and then to int for the final return value
    int reverseBits(int n) {
        bitset<32> bit(n);
        string bitString = bit.to_string();
        reverse(bitString.begin(), bitString.end());
        bitset<32> reversed(bitString);
        return (int)(reversed.to_ulong());
    }
};

int main() {
    Solution solution;

    assert(solution.reverseBits(43261596) == 964176192);
    assert(solution.reverseBits(2147483644) == 1073741822);

    cout << "solution has passed all of the defined testcases";
}