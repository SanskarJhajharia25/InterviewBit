/*

https://leetcode.com/problems/tuple-with-same-product/submissions/

Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.
*/
//The logic used is that we make an unordered map which stores the number of pairs (i,j) that lead to the same product. For each of them, the answer is 8 times. (simple obs)
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int,int> m;
        int ans = 0;
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < i ; ++j)
            {
                int p = nums[i] * nums[j];
                ans += 8 * m[p];
                m[p]+=1;
            }
        }
        return ans;
    }
};
