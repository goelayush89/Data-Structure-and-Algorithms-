class Solution {
public:
    int f(int i ,int j ,vector<vector<int>>& mt, vector<vector<int>>&dp){
        int n = mt.size();
        int m = mt[0].size();
        if(i==n || j== m) return 1e8;
        if(i==n-1 && j==m-1){
            if(mt[i][j]<0) return abs(mt[i][j])+1;
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int health = min(f(i+1,j,mt,dp) ,f(i,j+1,mt,dp));
        
        int res =0;
        if(health - mt[i][j] > 0){
            res = health - mt[i][j];
        }
        else res =1;
        return dp[i][j] = res;
        
        
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {         int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,dungeon,dp);
        
    }
};