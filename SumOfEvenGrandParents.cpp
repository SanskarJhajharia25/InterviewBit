/*
https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/submissions/

Given a binary tree, return the sum of values of nodes with even-valued grandparent.  (A grandparent of a node is the parent of its parent, if it exists.)

If there are no nodes with an even-valued grandparent, return 0.
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
       int fun(TreeNode* root)  //function to return it's value if exist or return 0
    {
        return root?root->val:0;   
    }
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) return 0;  //returns 0 if root is NULL
        queue<TreeNode*> q;
        q.push(root);  //push root node into the queue
        int sum=0;
        while(!q.empty())  //iterate the loop until the queue gets empty
        {
            TreeNode* temp=q.front();  //retrieving front of queue and pop it
            q.pop();
            if(temp->val%2==0)  //if it's value will be divisible by 2 then check for it's grandson
            { 
                //if it's left child exist then move to both left and right subtree of temp->left
                if(temp->left) sum+=fun(temp->left->left)+fun(temp->left->right); 
                //if it's right child exist then move to both left and right subtree of temp->right
                if(temp->right) sum+=fun(temp->right->left)+fun(temp->right->right);  

            }
            //if left child exist then push the left node to the queue
            if(temp->left) q.push(temp->left);  
            
              //if right child exist then push the right node to the queue
            if(temp->right) q.push(temp->right);
        }
        return sum;
    }
};
