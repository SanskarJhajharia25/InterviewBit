/*
https://www.interviewbit.com/old/problems/level-order/

Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).
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
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<TreeNode *> frontier = {A};
    vector<vector<int>> ans;
    while (!frontier.empty()) {
        vector<TreeNode *> next;
        vector<int> temp;
        for (auto x : frontier) {
            temp.push_back(x->val);
            if (x->left) next.push_back(x->left);
            if (x->right) next.push_back(x->right);
        }
        ans.push_back(temp);
        frontier = next;
    }
    return ans;
}
