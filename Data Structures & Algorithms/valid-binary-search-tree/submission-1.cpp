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
    bool solve(TreeNode* root, int mn, int mx){
        if(!root)
        return true;
        if(root->val>=mx || root->val<=mn)
        return false;
        return solve(root->left, mn, root->val) && solve(root->right, root->val, mx);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
        return true;
        return solve(root, INT_MIN, INT_MAX);
    }
};
