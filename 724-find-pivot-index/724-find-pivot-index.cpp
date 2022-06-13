class Solution {
public:
    int pivotIndex(vector<int>& nums) {
     int n = nums.size();
       int left_sum=0;
        int sum=0; 
        for (int x: nums) sum += x;
 
        for(int i=0;i<nums.size();i++){
          if(left_sum==sum-left_sum-nums[i]) return i;
            
            
            left_sum+=nums[i];
        }
        
        
        
       
        
        return -1;
    }
};