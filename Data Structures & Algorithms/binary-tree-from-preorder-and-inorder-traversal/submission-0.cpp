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
    int index=0;
    int find(int idx, vector<int>& inorder, int l, int r) {
        for(int i=l;i<=r;i++){
            if(idx == inorder[i])
            return i;
        }
        return -1;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        if(l>r)
        return NULL;
        int n=preorder.size();
        TreeNode* root = new TreeNode(preorder[index]);
        int pos = find(preorder[index], inorder, l, r);
        index++;
        root->left = build(preorder, inorder, l, pos-1);
        root->right = build(preorder, inorder, pos+1, r);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        TreeNode* root = build(preorder, inorder, 0, n-1);
        return root;
    }
};
