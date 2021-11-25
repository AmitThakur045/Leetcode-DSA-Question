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
    unordered_map<int, int> inorder_idx;
    TreeNode* solve(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe) {
        if(ps > pe || is > ie) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[pe]);
        int idx = inorder_idx[root->val];
        int numleft = idx - is;
        
        root->left = solve(inorder, is, idx - 1, postorder, ps, ps + numleft - 1);
        root->right = solve(inorder, idx + 1, ie, postorder, ps + numleft, pe -1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int is = 0, ie = inorder.size() - 1;
        int ps = 0, pe = postorder.size() - 1;
        
        for(int i=0; i<=ie; i++) {
            inorder_idx[inorder[i]] = i;    
        }
        
        return solve(inorder, is, ie, postorder, ps, pe);
    }
};
