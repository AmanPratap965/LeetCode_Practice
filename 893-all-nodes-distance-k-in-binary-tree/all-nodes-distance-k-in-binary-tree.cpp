/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parentMapping(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&parent){
        if(root==NULL)return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(root==NULL)return ans;
        unordered_map<TreeNode*,TreeNode*>parent;
        parentMapping(root,parent);

        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*,bool>vis;
        vis[target]=1;
        int dis=0;
        while(!q.empty()){
            
            int s=q.size();
            if(dis++==k)break;
            for(int i=0;i<s;i++){
                    TreeNode*node=q.front();
                    q.pop();
                    if(node->left && !vis[node->left]){
                        vis[node->left]=1;
                        q.push(node->left);
                    }
                    if(node->right && !vis[node->right]){
                        vis[node->right]=1;
                        q.push(node->right);
                    }
                    if(parent[node] && !vis[parent[node]]){
                        q.push(parent[node]);
                        vis[parent[node]]=true;
                    }
            }
        }
        vector<int>res;
        while(!q.empty()){
            TreeNode*curr=q.front();
            q.pop();
            res.push_back(curr->val);
        }
        return res;
    }
};