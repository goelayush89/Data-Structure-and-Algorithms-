class Solution {
public:
    
    
    void dfs(vector<vector<int>>& image,int initialColour, int newColor ,int i ,int j){
        int  n = image.size();
        int m = image[0].size();
        if(i<0 || j<0 ) return ;
        if(i>=n || j>=m) return ;
        
        
        if(image[i][j]!=initialColour) return;
        
        
        image[i][j]= newColor;
        
        dfs(image,initialColour,newColor,i-1,j);
        dfs(image,initialColour,newColor,i+1,j);
        dfs(image,initialColour,newColor,i,j-1);
        dfs(image,initialColour,newColor,i,j+1);
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        
        if(newColor==image[sr][sc]) return image;
        
        dfs(image,image[sr][sc],newColor,sr,sc);
        
        return image;
    }
};