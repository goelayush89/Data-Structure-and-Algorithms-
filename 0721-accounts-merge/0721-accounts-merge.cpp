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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
              
            int n = accounts.size();
          DisjointSet ds(n);
             unordered_map<string , int>mapMailNode;
            for(int i=0;i<n;i++){
                for(int j=1;j<accounts[i].size();j++){
                    if(mapMailNode.find(accounts[i][j]) == mapMailNode.end()){
                        mapMailNode[accounts[i][j]] = i;
                    }else{
                        
                        ds.unionByRank(i, mapMailNode[accounts[i][j]]);
                    }
                }
            }
        
        vector<string>MergedMail[n];
        
        for(auto it : mapMailNode){
            string mail = it.first;
            int node  = ds.findParent(it.second);
            MergedMail[node].push_back(mail);
        }
        
       vector<vector<string>>ans;
        
        
        for(int i=0;i<n;i++){
            if(MergedMail[i].size() == 0) continue;
            sort(MergedMail[i].begin() , MergedMail[i].end());
           
            
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it : MergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        
        return ans ;
        
    }
};