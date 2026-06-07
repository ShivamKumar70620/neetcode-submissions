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
    unordered_set<int> st;
    vector<int> ans;
    void recurse(TreeNode* root, int h){
        if(root==nullptr)
            return;
        if(!st.count(h)){
            ans.push_back(root->val);
            st.insert(h);
        }
        recurse(root->right, h+1);
        recurse(root->left, h+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)
            return {};
        recurse(root,0);
        return ans;
    }
};
