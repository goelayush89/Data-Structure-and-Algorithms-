class Solution {
public:
    
    void findComb(int i,unordered_map<char,string>&mp, string &temp,vector<string>&ans, string& digits){
        
    if(i==digits.length()) 
        {
            ans.push_back(temp);
            return ;
        }
    
        
        string str = mp[digits[i]];
        
        for(int j =0 ;j<str.length();j++){
            
            temp.push_back(str[j]);
            
            findComb(i+1,mp,temp,ans,digits);
            temp.pop_back();
            
        }
        
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        
        
        unordered_map<char,string>m;
        string temp;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        if(digits.length()==0){
            
            return ans;
        }
        findComb(0,m,temp,ans,digits);
        
        return ans;
        
    }
};