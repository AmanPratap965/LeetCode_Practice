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
int findPosition( vector<int>& in,int inorderStart,int inorderEnd,int element){
        for(int i=inorderStart;i<=inorderEnd;i++){
            if(element==in[i]){
                return i;
            }
        }
        return -1;
    }
    TreeNode*solve( vector<int>& in, vector<int>& pre,int &index,int inorderStart,int inorderEnd,int n, map<int,int>&mp){
        //base case
        if(index>=n || inorderStart>inorderEnd){
            return NULL;
        }
        
        int element=pre[index++];
     
        TreeNode*root=new TreeNode(element);
        int position=findPosition(in,inorderStart,inorderEnd,element);
        root->left=solve(in,pre,index,inorderStart,position-1,n,mp);
        root->right=solve(in,pre,index,position+1,inorderEnd,n, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
         int preOrderIndex=0;
        map<int,int>mp;
        int n=pre.size();
        for(int i=0;i<n;i++){
            mp[in[i]]=i;
        }
       TreeNode*ans= solve(in,pre,preOrderIndex,0,n-1,n,mp);
       return ans;
    }
};