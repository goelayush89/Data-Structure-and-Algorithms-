class Solution {
public:
       int dp(vector<int>& nums ,vector<int >& check,int idx){
        if(idx==nums.size()-1) return check[idx] = nums[idx];
        
        if(idx>=nums.size()) return  0;
        
        
        
        if(check[idx]!=-1) return check[idx];
        
        int take = nums[idx] + dp(nums,check ,idx+2);
        int nottake =   dp(nums,check ,idx+1);
        return check[idx]=  max(take,nottake);
        
        
    }
    int rob(vector<int>& nums) {
        
        
        vector<int>check(nums.size()+1,-1);
        int idx = 0;
        
        dp(nums,check,idx);
        
        return check[idx];
            
            
        
        
        
    }
};