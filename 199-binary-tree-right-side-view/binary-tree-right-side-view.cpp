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
    vector<int> rightSideView(TreeNode* root) {
        map<int,int>mp;
        vector<int>ans;
        if(root==NULL)return ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode*node=q.front().first;
                int lvl=q.front().second;
                q.pop();
                if(i==s-1)ans.push_back(node->val);
                if(node->left)q.push({node->left,lvl+1});
                if(node->right)q.push({node->right,lvl+1});
            }
        }
        return ans;
    }
};