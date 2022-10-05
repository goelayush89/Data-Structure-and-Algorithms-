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
    bool isValidBST(TreeNode* root) {
        return valid(root,LLONG_MIN,LLONG_MAX);
    }
    
    bool valid(TreeNode* root ,long long int minval,long long int maxval){
        if(!root) return true;
        
        if(root->val >=maxval || root->val <=minval) return false;
        
        return valid(root->left , minval,root->val) && valid(root->right , root->val,maxval);
    }
};