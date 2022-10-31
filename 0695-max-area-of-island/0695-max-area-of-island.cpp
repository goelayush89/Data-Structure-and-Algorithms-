class Solution {
public:
    void bfs(int i ,int j ,vector<vector<int>>& grid ,  vector<vector<int>>&vis , int &count ){
            int n = grid.size();
        int m = grid[0].size();
        
         queue<pair<int,int>>q;
         q.push({i,j});
        
        int dx[] ={1,0,-1,0};
        int dy[] = {0,1,0,-1};
        while(!q.empty()){
           auto node = q.front();
            int cx = node.first;
            int cy = node.second;
            q.pop();
            
            for(int i=0;i<4;i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
                
                if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && grid[nx][ny]==1){
                    
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                    count++;
                    
                }
            }
        }
        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
       vector<vector<int>>vis(n, vector<int>(m,0));
     
        int max_ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    vis[i][j]=1;
                    int temp =1;
                    bfs( i,j , grid ,vis,temp);
                    max_ans = max(max_ans, temp);
                }
            }
        }
        
        return max_ans;
    }
};