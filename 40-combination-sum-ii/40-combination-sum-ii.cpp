class Solution {
public:
    void getSubs(int ind,vector<vector<int>>&ans,vector<int>&ds,int target,vector<int>&candidates){
   if(ind==candidates.size()){    
        if(target==0){
            ans.push_back(ds);
            return;
        }
        return;
   }
        if(candidates[ind]<=target)
        {
        
            ds.push_back(candidates[ind]);
            getSubs(ind+1,ans,ds,target-candidates[ind],candidates);
            ds.pop_back();}
        
    while(ind+1<candidates.size() && candidates[ind] == candidates[ind+1]) ind++;
    getSubs(ind+1,ans,ds,target,candidates);
            
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        
        
        vector<int>ds;
        
    
        getSubs(0,ans,ds,target,candidates);
        return ans;
    }
};