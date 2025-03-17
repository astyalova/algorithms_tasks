/*
2529. Maximum Count of Positive Integer and Negative Integer
Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.

In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
Note that 0 is neither positive nor negative.
*/

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int idx_pos = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();
        int idx_neg = upper_bound(nums.begin(), nums.end(), -1) - nums.begin();
        
        int count_pos = n - idx_pos;
        int count_neg = idx_neg;

        return (count_neg >= count_pos) ? count_neg : count_pos;
    }
};
