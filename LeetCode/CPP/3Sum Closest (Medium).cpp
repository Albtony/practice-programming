#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int best = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) 
                continue;

            int left = i+1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < abs(best - target)) {
                    best = sum;
                }

                if (sum == target) {
                    return sum;
                } else if (sum > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }

        return best;
    }
};

int main() {
    Solution sol;

    assert(sol.threeSumClosest(vector<int> {-1,2,1,-4}, 1) == 2);
    assert(sol.threeSumClosest(vector<int> {0, 0, 0}, 1) == 0);
    cout << "Solution has passed all of the defined testcases";

    return 0;
}