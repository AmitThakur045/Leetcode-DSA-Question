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
    int res = 0;
    void solve(TreeNode* root, bool flag) {
        if(!root->left && !root->right) {
            if(flag == true)
                res += root->val;
            return;
        }
        if(root->right) solve(root->right, false);
        if(root->left) solve(root->left, true);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        bool flag = false;
        solve(root, flag);
        return res;
    }
};
