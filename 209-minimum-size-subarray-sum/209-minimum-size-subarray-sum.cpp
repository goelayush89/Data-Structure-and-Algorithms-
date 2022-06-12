class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left =0;
        int n = nums.size();
        
        int ans=INT_MAX;
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            
            
            while(sum>=target){
             ans = min(ans, i-left+1);
                
              sum-=nums[left++];
             
            
            }
            
            
        }
        if(ans!=INT_MAX){
        return ans;}else{return 0;}
    }
};