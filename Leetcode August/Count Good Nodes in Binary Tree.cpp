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
    int count = 0;
    void preOrder(TreeNode* root, int tmp) {
        if(root == NULL)
            return;
        
        if(root->val >= tmp) {
            tmp = root->val;
            count++;
        }
        preOrder(root->left, tmp);
        preOrder(root->right, tmp);
    }
    
    int goodNodes(TreeNode* root) {
        int tmp = INT_MIN;
        preOrder(root, tmp);
        return count;
    }
};
