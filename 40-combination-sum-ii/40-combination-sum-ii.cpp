class Solution {
public:
    void getSubs(int ind,vector<vector<int>>&ans,vector<int>&ds,int target,vector<int>&candidates){
        
        if(target==0){
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i-1]==candidates[i]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            getSubs(i+1,ans,ds,target-candidates[i],candidates);
            ds.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        
        
        vector<int>ds;
        
    
        getSubs(0,ans,ds,target,candidates);
        return ans;
    }
};