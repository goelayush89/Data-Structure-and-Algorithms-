class Solution {
public:
    bool pal(string &s,int i,int j){
    
  
    while(i<j){
        if(s[i++]!=s[j--]){
            return false;
            
        }
        
    }
    
    return true;
}
    int countSubstrings(string input) {
        int n= input.length();
    int cnt=0;
    for(int i=0;i<n;i++){
     
        for(int j=i;j<n;j++){
            
           
            if(pal(input,i,j)){
                cnt++;
            }
        }
    }
    
    return cnt;
    }
};