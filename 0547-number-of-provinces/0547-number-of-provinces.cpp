class Solution {
public:
        void bfs(int node ,  vector<int>&vis,vector<int>adj[]){
        queue<int>q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
       int fr = q.front(); 
       q.pop();
       
        for(auto i : adj[fr]){
            if(!vis[i]){
                vis[i]=1;
                q.push(i);
            }
            
        }
            
            
            
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int  V = adj[0].size();
       vector<int>adj_list[V];
        
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }
        
        
        vector<int>vis(V+1,0);
        int cnt=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bfs(i,vis,adj_list);
                cnt++;
            }
        }
        
        return cnt;
    }
};