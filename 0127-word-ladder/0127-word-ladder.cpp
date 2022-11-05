class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>>q;
        
        unordered_set<string>su(wordList.begin(),wordList.end());
        q.push({beginWord ,1});
        su.erase(beginWord);
        
        while(!q.empty()){
            
            string s = q.front().first;
             int depth = q.front().second;
            if(s==endWord) return depth;
            
            q.pop();
            for(int i=0;i<s.length();i++){
                char temp = s[i];
                for(char change ='a' ; change<='z';change++){
                    
                    s[i]=change;
                    
                    if(su.find(s)!=su.end()){
                        q.push({s,depth+1});
                        su.erase(s);
                    }
                }
                s[i]=temp;
            }
        }
        
        
        return 0;
    }
};