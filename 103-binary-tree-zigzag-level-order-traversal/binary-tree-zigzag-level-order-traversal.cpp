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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //bfs traversal
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        
            bool flag=0;//left-to-right
        while(!q.empty()){
            
            int s=q.size();
            vector<int>temp;
            
            for(int i=0;i<s;i++){
                TreeNode*node=q.front();
                q.pop();
                temp.push_back(node->val);
                //traversing through the neighbours
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                
            }
            if(!flag)ans.push_back(temp);
            else{
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            flag=!flag;
        }
        return ans;
    }
};