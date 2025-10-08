#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) 
                continue;

            int left = i+1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    vector<int> triplet = {nums[i], nums[left], nums[right]};
                    result.push_back(triplet);
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left-1]) left++; 
                    while(left < right && nums[right] == nums[right+1]) right--; 
                } else if (sum > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    auto expected = vector<vector<int>>{{0, 0, 0}};
    assert(sol.threeSum(vector<int>{0, 0, 0}) == expected);

    expected = vector<vector<int>>{{-1, -1, 2}, {-1, 0, 1}};
    assert(sol.threeSum(vector<int>{-1, 0, 1, 2, -1, -4}) == expected);

    expected = vector<vector<int>>{};
    assert(sol.threeSum(vector<int>{1, 2, -2, -1}) == expected);

    expected = vector<vector<int>>{{-2, 0, 2}, {-2, 1, 1}};
    assert(sol.threeSum(vector<int>{-2, 0, 1, 1, 2}) == expected);

    cout << "solution has passed all of the defined testcases"; 

    return 0;
}

/*
the approach is as follows

we are going to use a 2 pointer approach, with an additional 1 pointer, so 3 pointers
one pointer acts like an anchor and the initial pointer to the three, denoted by i on the for loop
then the other two uses the classic 2 pointers approach, left and right, we are going to use these pointers
to traverse the list logically based on sum

to traverse the list with two pointers logically based on sum, we need to sort the vector first
so i will start at the very first, left will start next to i (i+1), and right will start at the end of the list (vector.size() - 1)
this way, we have (anchor (smallest), smallest after anchor, biggest)

we can check the eligibility of the three numbers by adding them and checking the sum

if sum > 0, it means that we need to take a smaller number in the list, so right (biggest) moves backward to get the smaller biggest number
if sum < 0, it means that we need to take a bigger number in the list, so left (smallest after anchor) moves forward to get the bigger smallest after anchor number
and anchor stays the same,
if sum == 0, the condition is satisfied, we move the pointers by 1 (left++, right--), 

since we want unique triplets, we should check if our current components is a duplicate, if it is, then we skip it  
(nums[left] == nums[left-1]) left++ 
(nums[right] == nums[right+1]) right--

we skip both duplicates in left and right pointer at the same time since our current sum is 0,
so, if left/right change value by itself, the sum is guaranteed to be less/greater than 0,
hence we move both, so there is a + diff and a - diff, which potentially equates to 0

this way we are only checking each i at o(n) time,
meaning our final time complexity is o(n^2)
*/