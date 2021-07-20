/*
https://leetcode.com/problems/invert-binary-tree/submissions/
Given the root of a binary tree, invert the tree, and return its root.
*/

TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        TreeNode *right=invertTree(root->right);
        TreeNode *left=invertTree(root->left);
        root->left=right;
        root->right=left;
        return root;
    }
