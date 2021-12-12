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
    void solve(TreeNode* root, int &sum) {
        if(!root)
            return;
        
        solve(root->left, sum);
        solve(root->right, sum);
        
        int left = 0, right = 0;
        if(root->left)  left = root->left->val;
        if(root->right) right = root->right->val;
        sum += abs(left - right);
        root->val = root->val + left + right;
    }
    
    int findTilt(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return sum;
    }
};
