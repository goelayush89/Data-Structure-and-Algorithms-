class Solution {
public:
    
 void getSubs(int ind,vector<int>&nums,vector<vector<int>>&ans,vector<int>&ds ){
         ans.push_back(ds);
     for(int i =ind ;i<nums.size();i++){
         if(i>ind && nums[i]==nums[i-1]) continue;
         
         ds.push_back(nums[i]);
         getSubs(i+1,nums,ans,ds);
         ds.pop_back();
         
     }
     }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
               
     vector<int>ds;
        getSubs(0,nums,ans,ds);
        
        return ans;
    }
};