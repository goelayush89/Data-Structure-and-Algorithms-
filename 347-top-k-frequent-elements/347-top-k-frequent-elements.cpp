class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     
        unordered_map<int,int>mp;
        priority_queue<pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>>>p;
        for(auto i : nums){
            mp[i]++;
        }
        
        for(auto i = mp.begin();i!=mp.end();i++){
            p.push({i->second ,i->first});
            if(p.size()>k){
                p.pop();
            }
        }
        vector<int>v;
        while(!p.empty()){
            v.push_back(p.top().second);
            p.pop();
        }
        
        return v;
    }
};