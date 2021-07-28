/*
https://leetcode.com/problems/maximum-binary-tree/submissions/

You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

Create a root node whose value is the maximum value in nums.
Recursively build the left subtree on the subarray prefix to the left of the maximum value.
Recursively build the right subtree on the subarray suffix to the right of the maximum value.
Return the maximum binary tree built from nums.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return createTree(nums, 0, nums.size()-1);
    }
    
    
    TreeNode* createTree(vector<int> nums, int start, int end) 
    {
        if(start < 0 || end >= nums.size() || start > end) 
          return nullptr;
        int ind = start; int tmpMax = 0;
        for(int i=start; i<=end; i++) 
        {
            if(tmpMax <  nums[i]) 
            {
                tmpMax = nums[i];
                ind = i;
            }
        }
        TreeNode* tn = new TreeNode(tmpMax);
        tn->left = createTree(nums, start,ind-1); 
        tn->right = createTree(nums, ind+1, end);
        return tn;
    }
};
