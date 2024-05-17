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
    TreeNode*solve(vector<int>&inorder,vector<int>&postorder,int &index,int inStart,int inEnd,int n,map<int,int>&mapIndex){
        if(index<0 || inStart>inEnd)return NULL;
        int element=postorder[index--];
        //creating a node for the element
        TreeNode*root=new TreeNode(element);
        //finding the index in inorder
        int pos=mapIndex[element];
        //creating left and right nodes
        root->right=solve(inorder,postorder,index,pos+1,inEnd,n,mapIndex);
        root->left=solve(inorder,postorder,index,inStart,pos-1,n,mapIndex);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int postIndex=n-1;
        map<int,int>mapIndex;
        for(int i=0;i<n;i++){
            mapIndex[inorder[i]]=i;
        }
        TreeNode*ans=solve(inorder,postorder,postIndex,0,n-1,n,mapIndex);
        return ans;
    }
};