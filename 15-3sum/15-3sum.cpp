class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     
      vector<vector<int>>ans;
      sort(nums.begin(),nums.end());
        
       int n = nums.size(); 
        for(int i=0;i<n-2;i++){
            
            
            if(i==0 ||(i>0 && nums[i] != nums[i-1])){
                
                int lo = i+1 , hi = n-1, sum = 0-nums[i];
           while(lo<hi){
               
             if(nums[lo]+nums[hi]==sum){
                 
                 vector<int>temp;
                 temp.push_back(nums[lo]);
                   temp.push_back(nums[hi]);
                   temp.push_back(nums[i]);
                 ans.push_back(temp);
             
               
               while(lo<hi && nums[lo+1]==nums[hi]) lo++;
                while(lo<hi && nums[hi]==nums[hi-1]) hi--;
               
               
               lo++;hi--;
             }
               
                else if(nums[lo]+nums[hi]<sum) lo++;
               else hi--;
           }
                
               
            }
        }
          
        
        
    
        
        
        return ans;
    }
};