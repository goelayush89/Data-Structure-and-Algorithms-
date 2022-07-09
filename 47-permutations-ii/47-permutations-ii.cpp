class Solution {
public:
    
    void getPermutations(int ind, vector<int>&nums, vector<vector<int>>&ans){
        
        if(ind == nums.size()){
            ans.push_back(nums);
        }
        
        unordered_set<int>check;
        for(int i=ind;i<nums.size();i++){
            if(check.find(nums[i])!=check.end()) continue;
            check.insert(nums[i]);
            swap(nums[i],nums[ind]);
            getPermutations(ind+1,nums,ans);
            swap(nums[i],nums[ind]);
            
        }
        
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        getPermutations(0,nums,ans);
        return ans;
    }
};