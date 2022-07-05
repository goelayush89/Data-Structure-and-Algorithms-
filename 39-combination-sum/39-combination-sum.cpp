class Solution {
public:
    
    void getSubs(int i,vector<vector<int>>&ans, vector<int >&ds,vector<int>& candidates,int target,int sum){
        if(i>=candidates.size()) return ;
        if(sum>target){
            return;
        }
        
        if(target==sum){
            ans.push_back(ds);
            return;
        }
        ds.push_back(candidates[i]);
        
        getSubs(i,ans,ds,candidates,target,sum+candidates[i]);
        ds.pop_back();
        getSubs(i+1,ans,ds,candidates,target,sum);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
      vector<vector<int>>ans;
        
        
        vector<int >ds;
        
        getSubs(0,ans, ds,candidates,target,0);
        
        return ans;
        
    }
};