class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<int>ans;
        for(int i=0;i<m;i++){
            int cpos = i;
            int npos=-1;
            for(int j=0;j<n;j++){
                npos = cpos + grid[j][cpos]; 
                if(npos<0 || npos >=m || grid[j][cpos] != grid[j][npos]) {
                    cpos =-1; break;
                }
                
                cpos = npos;
                
            }
            ans.push_back(cpos);
            
    }
        return ans;}
};