class Solution {
public:
    
    int LCS(int i ,int j,string word1, string word2, vector<vector<int>>&dp){
        
        
        if(i==0|| j==0 ) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j] ;
        
        if(word1[i-1]==word2[j-1]) {
            
            return dp[i][j]=1+LCS(i-1,j-1,word1,word2,dp);
        }
            
     return dp[i][j]= max(LCS(i-1,j,word1,word2,dp),LCS(i,j-1,word1,word2,dp));
        
        
    }
    
    int minDistance(string word1, string word2) {
       int n = word1.length();
        int m = word2.length();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
           LCS(n,m,word1,word2,dp);
        
        int temp = dp[n][m];
        
        
        return m+n - 2*temp;
        
        
    }
};