class Solution {
public:
    
    int f(int i , int j , string word1, string word2, vector<vector<int>>&dp){
        if(i==0) return j;
        if(j==0) return i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i-1] == word2[j-1]){
           return dp[i][j] = f(i-1,j-1,word1,word2,dp);
            
        }else{
           int insert = 1+f(i,j-1,word1,word2,dp);
           int del    =  1+f(i-1,j,word1,word2,dp);
           int replace = 1+ f(i-1,j-1,word1,word2,dp);
           return dp[i][j] = min(insert,min(del,replace));
        }
        
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        for(int j=0;j<=m;j++) dp[0][j] =j;
         for(int i=0;i<=n;i++) dp[i][0] =i;
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(word1[i-1] == word2[j-1]){
         dp[i][j] = dp[i-1][j-1];
            
        }else{
           int insert = 1+dp[i][j-1];
           int del    =  1+dp[i-1][j];
           int replace = 1+dp[i-1][j-1];
            dp[i][j] = min(insert,min(del,replace));
        }
            }
        }
        return dp[n][m];
    }
};