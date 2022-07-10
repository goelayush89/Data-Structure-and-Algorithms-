class Solution {
public:
     bool isValid(string &s ,int start ,int end,int n , vector<string>& dict ){
        
         string check = s.substr(start,end-start+1);
        for(int i =0;i<n;i++){
         
            if(check == dict[i]) return true;
           
        }
         
        return false;
    }
    
    void solve(int index , string s , int n ,vector<string>&ans ,string &temp, vector<string>& dict){
       if(index == s.length()) {
           temp.pop_back();
            ans.push_back(temp);
            
            return;} 
        
        
        for(int i=index; i<s.length();i++){
            
            
            if(isValid(s,index,i,n,dict)){
                string temp2 =temp;
                temp+= s.substr(index,i-index+1);
                temp+=" ";
         
                solve(i+1,s,n,ans,temp,dict);
                
                temp = temp2;
            }
            
        }
        
    }
    
    
    
    vector<string> wordBreak(string s, vector<string>& dict) {
        // code here
            vector<string> ans;
            string temp ;
        int n = dict.size();
            
            solve(0,s,n,ans,temp,dict);
        return ans;
    }
};