class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
    queue<pair<pair<int,int>,int>>q;
        int vis[m][n] ;
        
        for(int i=0;i<m;i++){
            { for(int j=0;j<n;j++)
            { if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});}
                 else
                 {vis[i][j]=0;}
            }}}
        
        
        
        
        int tm=0;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;
            q.pop();
             tm = max(tm,t);
            
            int delrow[] = {-1,0,0,1};
            int delcol[] = {0 ,1 ,-1,0};
            
            for(int i=0;i<4;i++){
                
                int nrw = x+delrow[i];
                int ncol = y+delcol[i];
                
                if(nrw>=0 && nrw<m && ncol>=0 && ncol<n && grid[nrw][ncol]==1 &&  vis[nrw][ncol]!=2){
                    vis[nrw][ncol]=2;
                    q.push({{nrw,ncol},t+1});
                    
                }
                
            }
            
            
        }
        
         for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1 && vis[i][j]!=2) return -1;
        
        
        
        return tm;
    }
};