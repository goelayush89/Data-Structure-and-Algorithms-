class Solution {
public:
    
 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(grid[i][j]==2){
             q.push({{i,j},0});
            }
            
            }
        }
        int time=0;
         int dx[] = {-1,0, 0  ,1};
        int dy[] = { 0, 1 , -1 ,0 } ;
        while(!q.empty()){
           auto it = q.front();
            q.pop();
            
          int cx = it.first.first;
          int cy = it.first.second;
           time = it.second;
          for(int i=0;i<4;i++){
                int nx = cx+dx[i];
                int ny = cy + dy[i];
                
                
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1)
                {   grid[nx][ny]=2;
                    q.push({{nx,ny},time+1});
                }
            }
              
            
            
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(grid[i][j]==1){
           return -1;
            }
            
            }
        }
        
        return time;
        
        
        
        
        
    }
};