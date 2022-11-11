class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string , int>>q;
        
        q.push({startGene , 0});
       unordered_set<string>st(bank.begin(),bank.end());
        st.erase(startGene);
        while(!q.empty()){
            auto it  = q.front();
            string src = it.first;
            int level = it.second;
            q.pop();
            if(src == endGene) return level;
            
              char charList[]  = {'A', 'G','C','T'};
             for(int i=0;i<src.length();i++){
                 int org = src[i];
                 for(int j=0;j<4;j++){
                     char change = charList[j];
                     src[i] = change;
                     if(st.find(src)!=st.end()){
                         q.push({src,level+1});
                         st.erase(src);
                     }
                     src[i] = org;
                 }
                 
             }
        }
        
        
        return -1;
    }
};