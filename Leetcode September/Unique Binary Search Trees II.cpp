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
    vector<TreeNode*> generateAllBST(int start, int end) {
        vector<TreeNode*> res;
        if(start > end) {
            res.push_back(NULL);
            return res;
        }
        
        for(int i=start; i<=end; i++) {
            vector<TreeNode*> leftTree = generateAllBST(start, i-1);
            vector<TreeNode*> rightTree = generateAllBST(i+1, end);
            
            for(auto p : leftTree) {
                for(auto q : rightTree) {
                    TreeNode* root = new TreeNode(i);
                    root->left = p;
                    root->right = q;
                    
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return {};
        return generateAllBST(1, n);
    }
};
