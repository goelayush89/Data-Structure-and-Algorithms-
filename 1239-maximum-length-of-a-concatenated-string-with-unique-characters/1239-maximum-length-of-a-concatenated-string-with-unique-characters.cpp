class Solution {
public:
    
    bool compare(string &check , vector<int>&selected){
        vector<int>Selfselected(26,0);
        int n = check.size();
        for(int i=0;i<n;i++){
            if(Selfselected[check[i]-'a']==1) return false;
        
           Selfselected[check[i]-'a']=1;
            
            
        }
        
         for(int i=0;i<n;i++){
            if(selected[check[i]-'a']==1) return false;
       
        }
        return true;
        
        
        
    }
    
    int find(int i, vector<string>& arr, vector<int>&selected,int length){
        
        if(i==arr.size()) return length;
        
        
       if(compare(arr[i],selected)==false){
           
         return  find(i+1,arr,selected,length);
       }
           
           
           length+=arr[i].length();
           
          for(int k=0;k<arr[i].length();k++){
            selected[arr[i][k]-'a']=1;
       
        }
         int op1 =   find(i+1,arr,selected,length);
           
           
         
           length-=arr[i].length();
           
          for(int k=0;k<arr[i].length();k++){
            selected[arr[i][k]-'a']=0;
       
        }
         int op2=   find(i+1,arr,selected,length);
       
        
        return max(op1,op2);
        
    }
    int maxLength(vector<string>& arr) {
        vector<int>selected(26,0);
        string ans;
        int ans1 =find(0,arr,selected,0);
        
        return ans1;
        
    }
};