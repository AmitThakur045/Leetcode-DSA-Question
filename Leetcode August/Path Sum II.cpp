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
    void solve(TreeNode* root, vector<int>& tmp, vector<vector<int>>& res, int target) {
        if(!root)
            return;
        tmp.push_back(root->val);
        if(!root->left && !root->right && root->val == target)
            res.push_back(tmp);
        solve(root->left, tmp, res, target - root->val);
        solve(root->right, tmp, res, target - root->val);
        tmp.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> tmp;
        solve(root, tmp, res, targetSum);
        return res;
    }
};
