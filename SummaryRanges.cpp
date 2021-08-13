/*

https://leetcode.com/problems/summary-ranges/submissions/

You are given a sorted unique integer array nums.

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b

*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return {};
        if(size == 1) return {to_string(nums[0])};
        vector<string> res;
        int last = nums[0];
        for(int i = 1; i < size; i++)
        {
            if(nums[i] != nums[i-1] + 1)
            {
                if(nums[i-1] == last)
                    res.push_back(to_string(last));
                else
                    res.push_back(to_string(last) + "->" + to_string(nums[i-1]));
                last = nums[i];
            }
        }
        if(nums[size-1] == last) res.push_back(to_string(last));
        else res.push_back(to_string(last) + "->" + to_string(nums[size-1]));
        return res;
    }
};
