class Solution {
public:
   int lcs(int i , int j ,string &text1, string &text2,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0 ;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]) return dp[i][j] =  1+ lcs(i-1,j-1,text1,text2,dp);
       int a = lcs(i-1,j,text1,text2,dp) ;
       int b = lcs(i,j-1,text1,text2,dp);
       return dp[i][j] =  max(a,b);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
       
        return lcs(n-1,m-1,text1,text2,dp);
        
    }
};