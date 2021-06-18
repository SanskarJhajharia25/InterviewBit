//https://www.interviewbit.com/old/problems/binary-tree-from-inorder-and-postorder/
//https://www.interviewbit.com/old/problems/binary-tree-from-inorder-and-postorder/
/*
Given inorder and postorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
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
TreeNode* helper(vector<int> &A, int A1, int A2, vector<int> &B, int B1, int B2){
    if(A1 >= A2 || B1 >= B2) return nullptr;
    // root of entire tree is the last element of postorder
    TreeNode* root = new TreeNode(B[B2-1]);
    auto index = find(A.begin()+A1, A.begin()+A2, B[B2-1]);
    // searched for index of root in inorder. Left of this index in left subT and viceversa
    int diff = index - (A.begin()+A1); // left subT(how far it is from A1)
    root->left = helper(A, A1, A1+diff, B, B1, B1+diff);
    root->right = helper(A, A1+diff+1, A2, B, B1+diff, B2-1);
    return root;
}
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    // A is inorder and B is postorder
    int n = A.size();
    if(n == 0) return nullptr;
    
    return helper(A, 0, n, B, 0, n);
}
