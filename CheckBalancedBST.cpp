/*
Given a binary tree, determine if it is height-balanced.

 Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
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
int Solution::isBalanced(TreeNode* A) 
{
    if(A==NULL)
   return 1;
   
   if(A->left==NULL&&A->right!=NULL&&(A->right->right!=NULL||A->right->left!=NULL))
   return 0;
   if(A->right==NULL&&A->left!=NULL&&(A->left->left!=NULL||A->left->right!=NULL))
   return 0;
   
   return  isBalanced(A->left)&&isBalanced(A->right);
}
