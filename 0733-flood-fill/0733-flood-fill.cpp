class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int old =   image[sr][sc];
       if(old==color) return image;
        int dx[] = {-1,0, 0  ,1};
        int dy[] = { 0, 1 , -1 ,0 } ;
        while(!q.empty()){
            auto node = q.front();
            
            q.pop();
            int cx = node.first;
            int cy = node.second;
            image[cx][cy]=color;
            for(int i=0;i<4;i++){
                int nx = cx+dx[i];
                int ny = cy + dy[i];
                
                
                if(nx>=0 && ny>=0 && nx<n && ny<m && image[nx][ny]==old)
                {
                    q.push({nx,ny});
                }
            }
            
        
        
        
        
        }
        return image;
    }
};