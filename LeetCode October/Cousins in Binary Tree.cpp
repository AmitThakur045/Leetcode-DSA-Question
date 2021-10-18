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
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root)
            return false;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0, x_val = -1, y_val = -1;
        while(!q.empty()) {
            level++;
            // cout<<level<<endl;
            int size = q.size();
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->val == x) {
                    x_val = level;
                    // cout<<"abc"<<endl;
                }
                else if(node->val == y) {
                    y_val = level;
                    // cout<<"xyz"<<endl;
                }
                if(node->left && node->right) {
                if((node->right->val == x && node->left->val == y) || (node->right->val == y && node->left->val == x))
                    return false;
                }
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
        }
        // cout<<x_val<<" "<<y_val;
        return x_val == y_val;
    }
};
