class Solution {
public:
    void getComb(int i , int n , int k ,vector<vector<int>>&ans,vector<int>&ds)
    {
        
        if(k==0){
            ans.push_back(ds);
            
            return ;
        }
        if(i>n){
            return;
        }
        
        
        ds.push_back(i);
        getComb(i+1,n,k-1,ans,ds);
        ds.pop_back();
        getComb(i+1,n,k,ans,ds);
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>ds;
        getComb(1,n,k,ans,ds);
    return ans;}
};