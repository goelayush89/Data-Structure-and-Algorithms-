class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector< pair<int ,int >>graph[n];
        for(auto it : flights){
            graph[it[0]].push_back({it[1],it[2]});
            
        }
        
        queue<pair<int, pair<int ,int>>>q;
        
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src]=0;
        while(!q.empty()){
          auto it = q.front();
            q.pop();
          int s = it.second.first;
          int wt  = it.second.second;
          int stops = it.first;
          if(stops > k) continue;
            for(auto it : graph[s]){
                
            if(wt + it.second <= dist[it.first] && stops <=k){
                dist[it.first] = wt + it.second;
                q.push({stops+1,{ it.first , dist[it.first]}});
            }
              
                }
            
        }
        
        if(dist[dst]==1e9) return -1;
        return dist[dst];
            
    }
};