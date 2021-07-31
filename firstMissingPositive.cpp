/*

https://leetcode.com/problems/first-missing-positive/submissions/

(17) First Missing Positive - LeetCode
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
         int  ans = 1, i = 0, n = arr.size();
        int j = 0;
        while(i<n) {
            if(ans == arr[i] && j == -1) {
                ans++;
            }
            else if(ans == arr[i] && j != -1) {
                i = j;
                j = -1;
                ans++;
                continue;
            }
            if(ans<arr[i] && j == -1) {
                j = i;
            }
            i++;
        }
        return ans;  
    }
};
