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
    void solve(TreeNode* root, int num) {
        
        if(!root->left && !root->right) {
            res = res +  (num * 10 + root->val);
            return;
        }
        if(root->left)
            solve(root->left, num * 10 + root->val);
        if(root->right)
            solve(root->right, num * 10 + root->val); 
        
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        solve(root, 0);
        return res;
    }
};
