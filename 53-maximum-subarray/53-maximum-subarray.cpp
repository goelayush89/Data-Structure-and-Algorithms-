class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        if(nums.size()==1) return nums[0];
        int max1=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            
            sum = sum+nums[i];
            sum = max(sum ,nums[i]);
          max1 = max(max1,sum);
            
        
        }
        
        return max1;
    }
};