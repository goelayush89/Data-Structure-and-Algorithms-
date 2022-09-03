class Solution {
private: 
    void bfs(int row ,int col , vector<vector<int>>&vis, vector<vector<char>>& grid){
        
        vis[row][col] = 1;
        queue<pair<int, int>>q;
        int m = grid.size();
        int n = grid[0].size();
        q.push({row,col});
        
        while(!q.empty()){
           int x = q.front().first;
           int y = q.front().second;
           q.pop();
            
            for(int i=-1;i<=1;i++){
                for(int j =-1 ;j<=1;j++){
            if(i== -1 && j==0  || i==1 && j==0 || i==0 && j==1  || i==0 && j==-1){
                  int nrow = x+i;
                  int ncol = y+j;
                
                if(nrow>=0 && nrow< m && ncol>=0 && ncol< n && grid[nrow][ncol]=='1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
                
                
            }
                }
            }
            
            
        }
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int cnt=0;
        for(int row=0;row<m;row++){
            for(int col = 0;col<n;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    bfs(row,col,vis,grid);
                    cnt++;
                }
                
            }
            
        }
        
        return cnt;
        
    }
};