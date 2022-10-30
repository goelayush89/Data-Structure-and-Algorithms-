class Solution {
public:
    
    void bfs(int i ,int j , vector<vector<int>>&vis,vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        
       queue<pair<int,int>>q;
        
        q.push({i,j});
        vis[i][j]=1;
        int dx[] = {-1,0,1,0};
        int dy[] = { 0, 1,0,-1};
        
        while(!q.empty()){
             auto node  = q.front();
             int cx = node.first;
             int cy = node.second;
             q.pop();
              for(int i=0;i<4;i++){
                  int nx = cx+dx[i];
                  int ny = cy + dy[i];
                  
              if(nx<n && ny<m && nx>=0 && ny>=0 && !vis[nx][ny] && grid[nx][ny]=='1' ){
                  q.push({nx,ny});
                  vis[nx][ny]=1;
              }
              }
            
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
          int n = grid.size();
          int m = grid[0].size();
          vector<vector<int>>vis(n,vector<int>(m,0));
          int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    if(!vis[i][j]){
                        cnt++;
                        bfs(i,j,vis,grid);
                    }
                }
            }
        }
        
        return cnt;
    }
};