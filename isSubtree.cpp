/*
https://leetcode.com/problems/subtree-of-another-tree/submissions/
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.
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
    bool isSame(TreeNode* l, TreeNode* r) const {
        if(!l || !r) {
            if(!l && !r)
                return true;
            else
                return false;
        }
        if(l->val != r->val)
            return false;
        return isSame(l->left, r->left) && isSame(l->right, r->right);
    }
    
    bool isSubtree(TreeNode* r, TreeNode* sr) const {
        if(isSame(r, sr))
            return true;
        if(!r)
            return false;
        return isSubtree(r->left,sr) || isSubtree(r->right,sr);
    }
};
