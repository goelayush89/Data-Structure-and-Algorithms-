class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, pair<int,int>>>p;
        for(int i=0;i<n;i++){
            
            p.push({pow(points[i][0],2) + pow(points[i][1],2),{points[i][0],points[i][1]}});
                if(p.size()>k) p.pop();
            
            
        }
        vector<vector<int>>ans;
        while(!p.empty()){
            auto top = p.top();
            ans.push_back({top.second.first ,top.second.second});
        
         p.pop();
        }
        
        return ans;
    }
};