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
    bool solve(TreeNode*r1,TreeNode*r2){
        if(r1==NULL || r2==NULL)return r1==r2;
        return r1->val==r2->val && solve(r1->left,r2->right) && solve(r1->right,r2->left);

    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return solve(root->left,root->right);
    }
};