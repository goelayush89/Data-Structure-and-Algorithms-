#include <bits/stdc++.h>
class Solution {
public:
    bool isValid(string &s,int start,int end){
        if(start != end and s[start]=='0') return false;
         
        
    
        string temp = s.substr(start, end-start+1);
        int res = stoll(temp);
        if(res>=0 and res<=255) return true;
        return false;
    }
    
    void restoreIpAdd(int index, string &s, string &path , vector<string>&res,int cnt){
       if(cnt>4) return;
        if(index==s.length()){
             if(cnt==4) 
             { path.pop_back();
            res.push_back(path);}
            return;
        }
        
        for(int i=index;i<s.length();i++){
            if(isValid(s,index,i)){
                string temp = path;
                path= path + s.substr(index,i-index+1);
                path.push_back('.');
                cnt++;
                restoreIpAdd(i+1,s,path,res,cnt);
                path= path + s.substr(index,i-index+1);
               path = temp;
                  cnt--;
            }
            
            
        }
        
        
    }
    
    vector<string> restoreIpAddresses(string s) {
          vector<string>res;
            string path ;
             restoreIpAdd(0,s,path,res,0);
        
        return res;
    }
};