class Solution {
public:
    
 int dfs(int i ,int j ,vector<vector<int>>& grid ,vector<vector<int>>&dp ){
           
        int count=0;
        int n = grid.size();
        int m = grid[0].size();
        int dx[] ={0,0,-1,1};
        int dy[] = {1,-1,0,0};
         if(dp[i][j]!=-1) return  dp[i][j];
        for(int ind =0;ind<4;ind++){
              
            int nx = i+dx[ind];
            int ny = j+dy[ind];
        if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]>grid[i][j])         {  count  = max(count ,1+dfs(nx,ny,grid,dp));
                   
                   }  
                
        }
       
         return dp[i][j] = count; }
        
    
    int longestIncreasingPath(vector<vector<int>>& grid) {
        
         int n = grid.size();
         int m = grid[0].size();
         vector<vector<int>>dp(n,vector<int>(m,-1));
        int max_ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1)    
                {  int ans =  1+ dfs( i,j , grid ,dp);
                
                    max_ans = max(max_ans, ans);}
                }
            }
        
        
        return max_ans;
    }
    
};



