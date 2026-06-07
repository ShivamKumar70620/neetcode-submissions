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
    bool checkBST(TreeNode* root, int mn, int mx){
        if(root==nullptr)
            return true;
        if(root->val<mn || root->val>mx)
            return false;
        return checkBST(root->left,mn, root->val-1) && checkBST(root->right,root->val+1,mx);
    }
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)
            return true;
        return checkBST(root,INT_MIN,INT_MAX);
    }
};
