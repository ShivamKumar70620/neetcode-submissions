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
    int findH(TreeNode* root){
        if(root==NULL)
            return 0;
        return max(findH(root->left), findH(root->right)) + 1;
    }
    bool isBalance = true;
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        
        int lh = findH(root->left);
        int lr = findH(root->right);
        if(abs(lr-lh)>1){
            return false;
        }
        
        return isBalanced(root->right) && isBalanced(root->left);;

    }
};
