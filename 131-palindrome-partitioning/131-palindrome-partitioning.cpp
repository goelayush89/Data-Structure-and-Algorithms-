class Solution {
public:
    
    bool isPalindrome(string &s , int start , int end){
        
        while(start<end){
            if(s[start++] != s[end--]) return false;
            
        }
        
        return true;
    }
    void partition(int index,string &s,  vector<vector<string>>&ans,vector<string> &res ){
        
        if(index== s.length()){
            ans.push_back(res);
            return ;
        }
        for(int i = index ;i<s.length();i++){
            if(isPalindrome(s,index,i)){
                res.push_back(s.substr(index, i-index+1));
                partition(i+1,s,ans,res);
                res.pop_back();
            }
            
            
        }
        
    }
    vector<vector<string>> partition(string s) {
        
         vector<vector<string>> ans;
           vector<string> res;
        
        partition(0,s,ans,res);
        
        return ans;
        
    }
};