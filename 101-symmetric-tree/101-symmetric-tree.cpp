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
    
    
    bool checkSym(TreeNode* node1 , TreeNode* node2){
        
        if(!node1 || !node2) return node1==node2;
        
        if(node1->val != node2->val) return false;
        
        return checkSym(node1->left,node2->right) && checkSym(node1->right,node2->left);
        
    }
    
    bool isSymmetric(TreeNode* root) {
     
        return root==NULL || checkSym(root->left,root->right);
        
    }
};