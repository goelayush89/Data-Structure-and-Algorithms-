class Solution {
public:
    void solve(int n , int k ,vector<int>&result ,int num){

     if(n==0) {
         
         result.push_back(num);
         return ;}
        
        int tail = num%10;
        vector<int>possible;
        
        possible.push_back(tail+k);
     if(k!=0)
        possible.push_back(tail-k);
        
        
        for(auto x : possible){
            
            if(x>=0 && x<=9){
                int nw = num*10 + x;
                solve(n-1,k,result,nw);
            }
            
        }
    
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        
        if(n==1) return {0,1,2,3,4,5,6,7,8,9};
        vector<int>result;
        
        for(int i=1;i<=9;i++){
            solve(n-1,k,result,i);
          }
        
        
        return result;
    }
};