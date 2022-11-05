class Solution {
public:

    string alienOrder(vector<string>& words) {
           unordered_map<char ,int>indegree;  
        for(auto word : words){
           for(auto ch : word){
               indegree[ch]=0;
           }
       }
      
      unordered_map<char, vector<char>>graph;
        
          
     for(int i=0;i<words.size()-1;i++){
        string s1 = words[i];
        string s2 = words[i+1];
         int minSize = min(s1.length(),s2.length());
         int cnt=0;
        for(int j=0;j<minSize;j++){
             indegree[s1[j]]=0;
                indegree[s2[j]]=0;
            if(s1[j]!=s2[j]){
                graph[s1[j]].push_back(s2[j]);
               
                cnt++;
                break;
                    
            }
            
        }
         if(cnt==0 && s1.length() > s2.length()) return "";
            
     }

    vector<char>topo;
                                                
                                                                        
        for(auto it : graph){
            for(auto x : it.second){
                indegree[x]++;
            }
        }

        for(auto it : indegree){
           cout << it.first  << it.second << "\n";
        }
                                                         
                                                                       
queue<char>q;
                                                        
        for(auto it : indegree){
            if(it.second==0) q.push(it.first);
        }
                    
                                                                        while(!q.empty())
    {
        
      char node = q.front();
        q.pop();
        topo.push_back(node);
        
        for(auto it : graph[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
           
                                                                        cout << topo.size();
 string ans ="";                                                        for(int i=0 ;i<topo.size();i++){
                                                                         ans.push_back(topo[i]);
                                                                        }
   return ans.size() == indegree.size() ? ans : "";
       
        
        
    }
};