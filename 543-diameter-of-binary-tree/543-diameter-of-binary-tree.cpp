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
    int height(TreeNode* root ){
        if(!root) return 0;
        
    return 1+ max(height(root->left),height(root->right));
    }
    
    
    void findMax(TreeNode* root , int &maxi){
        if(!root) return ;
        
        int lh = height(root->left);
        int rh = height(root->right);
        maxi = max(maxi ,lh+rh);
        
        findMax(root->left , maxi);
         findMax(root->right , maxi);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
    
        int maxi=0;
        
        findMax(root,maxi);
        return maxi;

    }
};