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
    long sum = 0, res = 0, tmp;
    
    int solve(TreeNode* root) {
        if(!root)
            return 0;
        tmp = root->val + solve(root->left) + solve(root->right);
        res = max(res, (sum - tmp) * tmp);
        return tmp;
    }
    
    int maxProduct(TreeNode* root) {
        sum = solve(root);
        solve(root);
        return res % (int)(1e9 + 7);
    }
};
