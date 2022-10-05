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
    
    TreeNode* Create(vector<int>& preorder, int ps ,int pend, vector<int>& inorder ,int is , int iend , map<int ,int >&mp){
        
        
        
        if(ps>pend || is>iend) return NULL;
        
        TreeNode* root = new TreeNode(preorder[ps]);
        
       int  inRoot = mp[root->val];
        int numsleft = inRoot -is;
        
        root->left = Create(preorder,ps+1,ps+numsleft,inorder,is,inRoot-1,mp);
        root->right = Create(preorder,ps+numsleft+1,pend,inorder,inRoot+1,iend,mp);
        
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
           map<int ,int >mp;
        
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] =i;
            
        }
        
        
        return Create(preorder,0,preorder.size()-1,inorder,0 , inorder.size()-1,mp);
    }
};