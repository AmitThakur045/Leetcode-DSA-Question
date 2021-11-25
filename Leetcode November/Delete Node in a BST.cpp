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
    TreeNode* find_successor(TreeNode* node) {
        TreeNode* tmp = node->right;
        while(tmp->left) {
            tmp = tmp->left;
        }
        return tmp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        if(root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if(root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if(!root->right) {
                TreeNode* tmp = root->left;
                delete(root);
                return tmp;
            } else if(!root->left) {
                TreeNode* tmp = root->right;
                delete(root);
                return tmp;
            } else {
                TreeNode* succ = find_successor(root);
                swap(succ->val, root->val);
                root->right = deleteNode(root->right, key);
            }
        }
        return root;
    }
};
