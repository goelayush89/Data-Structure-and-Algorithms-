/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    
void   preorder(TreeNode* original, TreeNode* cloned, TreeNode* target ,TreeNode * &ans   ){
         if(original== NULL) return   ;
       
         if(original == target) {  
             
            ans =  cloned; }
       
          preorder(original->left,cloned->left,target,ans);
          preorder(original->right,cloned->right ,target,ans);
      
      
       }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
       
         TreeNode * ans = NULL;
        
         preorder(original,cloned,target,ans);
        
        return ans;
    }
};