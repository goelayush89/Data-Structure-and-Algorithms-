class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        unordered_map<char,int> indegree;
        unordered_map<char,vector<char>> adj;
        
        for(auto word: words)
        {
            for(auto c: word)
            {
                indegree[c]=0;
            }
        }
        
        for(auto it : indegree) cout << it.first << it.second;
        //create graph
        string prevword;
        string curword;
        for(int k=1;k<n;k++)
        {
            prevword = words[k-1];
            curword = words[k];
            int i=0,j=0;
            while(i<prevword.size() and j<curword.size())
            {
                if(prevword[i]!=curword[j])
                {
                    adj[prevword[i]].push_back(curword[j]);
                    indegree[curword[j]]++;
                    break;
                }
                i++; j++;
            }
            if(i!=prevword.size() and j==curword.size()) return "";
        }
        
        queue<char> q;
        for(auto i: indegree)
        {
            if(i.second==0)
            {
                q.push(i.first);
            }
        }
        
        //topo sort
        
        string res;
        while(!q.empty())
        {
            char i = q.front();
            q.pop();
            res+=i;
            for(int j=0;j<adj[i].size();j++)
            {
                indegree[adj[i][j]]--;
                if(indegree[adj[i][j]]==0)
                    q.push(adj[i][j]);
            }
        }
        
      
        return (res.size()==indegree.size()) ? res : "";
    }
};