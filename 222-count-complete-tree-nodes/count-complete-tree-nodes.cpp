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
    int left(TreeNode*root){
        if(root==NULL)return 0;
        
        return left(root->left)+1;
    }
    int right(TreeNode*root){
        if(root==NULL)return 0;
        
        return right(root->right)+1;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int lh=left(root);
        int rh=right(root);
        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};