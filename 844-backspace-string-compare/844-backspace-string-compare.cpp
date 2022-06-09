class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        
        int n = s.length()-1;
        int m = t.length()-1;
        int skipS =0,skipT=0;
       // if(n!=m) return false;
        
        while(n>=0 || m>=0){
            
            while(n>=0){
                if(s[n]=='#'){skipS++ ; n--;}
                else if(skipS>0){skipS--;n--;}
                else break;
                
            }
            while(m>=0){
                if(t[m]=='#'){skipT++ ; m--;}
                else if(skipT>0){skipT--;m--;}
                else break;
                
            }
            
            
            if(n>=0 && m>=0 && s[n]!=t[m]){
                return false;
            }
            if((n>=0)!=(m>=0)) return false;
            n--;
            m--;
        }
        
        return true;
    }
};