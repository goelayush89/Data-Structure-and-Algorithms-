class DisjointSet{
    vector<int>rank,parent ,size;
    
    public:
   DisjointSet(int n){
        rank.resize(n+1);
        parent.resize(n+1);
        size.resize(n+1);
       
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    
    
    int findParent(int node){
    if(parent[node] ==node) return node;
    return parent[node] = findParent(parent[node]);
}
    
    void unionByRank(int u ,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return ;
        
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u]=ulp_v;
        }else   if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v]=ulp_u;
        }else {
             parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
        
        }
    
    void unionBySize(int u ,int v){
         int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return ;
        
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else    {
             size[ulp_u]+=size[ulp_v];
            parent[ulp_v]=ulp_u;
        }
    }
    
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges=0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            
            if(ds.findParent(u)==ds.findParent(v)) extraEdges++;
            
            else {
                ds.unionBySize(u,v);
            }
            
        }
        int Connected=0;
        for(int i=0;i<n;i++){
            if(ds.findParent(i)==i) Connected++;
        }
        int ans = Connected-1;
        if(extraEdges>=ans){
            return ans;
        }
        
        return -1;
    }
};