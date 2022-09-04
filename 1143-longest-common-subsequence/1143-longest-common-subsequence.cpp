class Solution {
public:
    int LCS(int i ,int j , string &text1, string &text2, vector<vector<int>>&dp){
        
        if(i==0 || j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i-1]==text2[j-1])  return  dp[i][j] = 1+ LCS(i-1,j-1,text1,text2,dp);
        return  dp[i][j] = max(LCS(i-1,j,text1,text2,dp),LCS(i,j-1,text1,text2,dp));
        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
      
        int n = text1.length();
        int m = text2.length();
         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return LCS(n,m,text1,text2,dp);
        
    }
};