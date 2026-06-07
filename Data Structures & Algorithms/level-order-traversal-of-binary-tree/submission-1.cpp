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
    map<int, vector<int>> mp;
    void recurse(TreeNode* root, int h){
        if(root==NULL)
            return;
        mp[h].push_back(root->val);
        recurse(root->left, h+1);
        recurse(root->right, h+1);

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> t;
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                t.push_back(temp->val);
                if(temp->left!=nullptr){
                    q.push(temp->left);
                }
                if(temp->right!=nullptr)
                    q.push(temp->right);
            }
            res.push_back(t);
        }

        return res;

    }
};
