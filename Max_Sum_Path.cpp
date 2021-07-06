/*
https://www.interviewbit.com/old/problems/max-sum-path-in-binary-tree/

https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/

Given a binary tree T, find the maximum path sum.

The path may start and end at any node in the tree.

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int helper(TreeNode *root,int &ans)
{
    if(!root)
    {
        return 0;
    }
    int l=helper(root->left,ans);
    int r=helper(root->right,ans);
    int val=root->val+max(l,r);
    ans=max(ans,max(val,max(root->val,l+root->val+r)));
    return val;
}
int Solution::maxPathSum(TreeNode* A) 
{
    int ans=INT_MIN;
    helper(A,ans);
    return ans;
}
