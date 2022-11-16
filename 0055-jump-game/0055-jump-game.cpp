class Solution {
public:
    bool jump(int i,vector<int>& nums,vector<int>&dp){
        if(i==nums.size()-1) return dp[i] = true;
        if(dp[i]!=-1) return dp[i];
        int far = min(i + nums[i],(int)nums.size()-1);
        for(int j=i+1 ; j<=far;j++){
            if(jump(j,nums,dp)) return dp[j] = true;
        }
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return jump(0,nums,dp);
    }
};