class Solution {
public:
    int climb(int i ,int n,vector<int>&dp){
         
        if(i==n) return 1;
        if(i>n) return 0;
       if(dp[i]!=-1) return dp[i];
        return  dp[i] = climb(i+1,n,dp)+climb(i+2,n,dp);
        
        
    }
    int climbStairs(int n) {
      vector<int>dp(n+1,-1);
        
        climb(0,n,dp);
        
      
        return dp[0];
        
    }
};