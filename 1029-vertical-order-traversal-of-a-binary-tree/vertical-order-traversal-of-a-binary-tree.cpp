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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        map<int,map<int,vector<int>>>mp;//{dis,lvl,list}
        queue<pair<TreeNode*,pair<int,int>>>q;//{dis,listofNOdes}
        q.push({root,{0,0}});//{node,{dis,lvl}}
        while(!q.empty()){
            int s=q.size();
             
            for(int i=0;i<s;i++){
                auto it=q.front();
                TreeNode*node=it.first;
                int dis=it.second.first;
                int lvl=it.second.second;
                q.pop();
                mp[dis][lvl].push_back(node->val);
                if(node->left)q.push({node->left,{dis-1,lvl+1}});
                if(node->right)q.push({node->right,{dis+1,lvl+1}});
            }
        }

        for(auto i:mp){
            vector<int>res;
            for(auto j:i.second){
               vector<int>&v=j.second;
               sort(v.begin(),v.end());
               res.insert(res.end(),v.begin(),v.end());
            }
            ans.push_back(res);
        }
        return ans;
    }
};