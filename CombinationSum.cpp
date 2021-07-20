/*
https://leetcode.com/problems/combination-sum/submissions/

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<int> current;
    
    void solve(vector<int>& candidates, int target, int idx)
    {
        if(target == 0)
        {
            res.push_back(current);
            return;
        }
        
        if(idx == candidates.size() || target < 0)
            return;
        current.push_back(candidates[idx]);
        solve(candidates, target - candidates[idx], idx);
        current.pop_back();
        solve(candidates, target, idx + 1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        solve(candidates, target, 0);
        return res;
    }
};
