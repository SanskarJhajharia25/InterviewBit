/*
https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/submissions/

Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.
*/

class Solution {
public:
    bool check(vector<int>& nums) {
           int x=nums[0];
        int flag=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>nums[i])
            {
                if(flag!=0)
                    return false;
                flag=1;
            }
            if(flag && nums[i]>x)
                return false;
        }
            
        return true;
    }
};
