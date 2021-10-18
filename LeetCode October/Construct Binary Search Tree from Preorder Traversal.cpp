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
    int i = 0;
    TreeNode* solve(vector<int> preorder, int prev) {
        if(preorder.size() == i || preorder[i] > prev)    return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = solve(preorder, root->val);
        root->right = solve(preorder, prev);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder, INT_MAX);
    }
};
