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
    void dfs(TreeNode* root, int k , priority_queue<int> &pq){
        if(!root)
        return;
        dfs(root->right, k, pq);
        pq.push(root->val);
        if(pq.size()>k)
        {
            pq.pop();
        }
        dfs(root->left, k, pq);
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        dfs(root, k, pq);
        return pq.top();
    }
};
