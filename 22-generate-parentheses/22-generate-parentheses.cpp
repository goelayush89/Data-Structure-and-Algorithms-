class Solution {
public:
    
    void find(vector<string>&ans, string &temp ,int open, int close){
        
        if(close==0 and open==0){
            ans.push_back(temp);
            return;
        }
        
      if(open>0){  
        temp+='(';
          find(ans,temp,open-1,close);
          temp.pop_back();
      }
        if(close>0){
            
            if(open<close){
                temp+=')';
              find(ans,temp,open,close-1);
                temp.pop_back();
            }
        }
        
    
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
         string temp;
        
        
        find(ans,temp,n,n);
        
        return ans;
    }
};