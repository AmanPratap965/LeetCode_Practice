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
    TreeNode*findRight(TreeNode*root){
        if(root->right==NULL)return root;
        return findRight(root->right);
    }
    TreeNode* helper(TreeNode*root){
        if(root->left==NULL)return root->right;
        else if(root->right==NULL)return root->left;
        TreeNode*rightChild=root->right;
        TreeNode*lastRight=findRight(root->left);
        lastRight->right=rightChild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        //first search for the key 
        if(root->val==key){
           return helper(root);
        }
        TreeNode*dummy=root;
        while(root){
            if(root->val>key){
                    if(root->left!=NULL && root->left->val==key){
                        // TreeNode*old=root->right;
                        root->left=helper(root->left);
                        // delete(old);
                        break;
                    }else root=root->left;
            }
            else{
                if(root->right!=NULL && root->right->val==key){
                    // TreeNode*old=root->right;
                    root->right=helper(root->right);
                    // delete(old);
                    break;
                }else root=root->right;
            }
        }
        return dummy;
    }
};