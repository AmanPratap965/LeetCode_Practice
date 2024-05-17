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
    int findElement(vector<int>&inorder,int element){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==element)return i;
        }
        return -1;
    }
    TreeNode*solve(vector<int>&inorder,vector<int>&preorder,int &index,int inStart,int inEnd,int n){
        if(index>=n || inStart>inEnd)return NULL;
        int element=preorder[index++];
        TreeNode*root=new TreeNode(element);
        int pos=findElement(inorder,element);
        root->left=solve(inorder,preorder,index,inStart,pos-1,n);
        root->right=solve(inorder,preorder,index,pos+1,inEnd,n);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex=0;
        int n=inorder.size();
        TreeNode*ans=solve(inorder,preorder,preorderIndex,0,n-1,n);
        return ans;
    }
};