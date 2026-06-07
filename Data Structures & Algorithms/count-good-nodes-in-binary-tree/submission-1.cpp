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
    int recurse(TreeNode* root, int mx){
        if(root==NULL)
            return 0;
        int a = 0;
        if(mx<=root->val)
            a+=1;
        return a + recurse(root->left, max(mx,root->val)) + recurse(root->right,max(mx,root->val));
        
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        return recurse(root, root->val);
    }
};
