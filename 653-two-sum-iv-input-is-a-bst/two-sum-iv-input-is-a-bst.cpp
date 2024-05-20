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
 class BSTIterator1 {
    stack<TreeNode*>st;
public:
    void pushAll(TreeNode*root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    BSTIterator1(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode*tmp=st.top();
        st.pop();
        pushAll(tmp->right);
        return tmp->val;
    }
    
    bool hasNext() {
     return !st.empty();   
    }
};
class BSTIterator2 {
    stack<TreeNode*>st;
public:
    void pushAll(TreeNode*root){
        while(root){
            st.push(root);
            root=root->right;
        }
    }
    BSTIterator2(TreeNode* root) {
        pushAll(root);
    }
    
    int before() {
        TreeNode*tmp=st.top();
        st.pop();
        pushAll(tmp->left);
        return tmp->val;
    }
    
    bool hasbefore() {
     return !st.empty();   
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator1 bs1(root);
        BSTIterator2 bs2(root);
        int i=bs1.next();
        int j=bs2.before();
        while(i<j){
            if(i+j==k)return true;
            else if(i+j>k){
                j=bs2.before();
            }else {
                i=bs1.next();
            }
        }
        return false;
    }
};