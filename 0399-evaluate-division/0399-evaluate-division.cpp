class Solution {
public:
    
   void findPath(string s , string d , set<string>&st ,  map<string , vector<pair<string , double>>>&mp , double &ans , double temp ){
        if(st.find(s)!=st.end()) return;
        st.insert(s);
       if(s==d) {ans = temp ; return ;}
       
       else{
           for(auto it : mp[s]){
               double mult = it.second;
              findPath(it.first , d , st, mp,ans , temp*mult);
           }
       }
       
        
        
        
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        
        map<string , vector<pair<string , double>>>mp;
        vector<double>answer;
        for(int i=0;i<equations.size();i++){
             string u = equations[i][0];
             string v = equations[i][1];
             double wt = values[i];
             mp[u].push_back({v,wt});
             mp[v].push_back({u,1/wt});
        }
        
        
        for(int i=0;i<queries.size();i++){
            string source = queries[i][0];
            string destination = queries[i][1];
            double temp_ans = -1.0;
            double temp = 1.0;
            set<string>s;
            if(mp.find(source)!= mp.end() && mp.find(destination)!=mp.end()){
              findPath(source , destination ,s,mp,temp_ans , temp);
            }
            answer.push_back(temp_ans);
            
            
        }
        
        return answer;
    }
};