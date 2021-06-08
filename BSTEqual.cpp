/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
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
int Solution::isSameTree(TreeNode* A, TreeNode* B) 
{
    if(!A && !B) // if there is no node both sub-tree/ tree
      return 1;
    if(!A || !B) // if any one of sub-tree/tree have no nodes
      return 0;
    if(A->val != B->val) // if values of root node is not equal
      return 0;
// if all above are true check sub tree of the trees satisfy or not
    return isSameTree(A->left,B->left) && isSameTree(A->right,B->right);
    
}
