class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum=nums[0] + nums[1] + nums[2];
       
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            int low = i+1;
            int end = n-1;
            
            while(low<end){
                int curr_sum = nums[i]+nums[low]+nums[end];
                
                if(curr_sum<target){
                          low++;
                
                }else{
                    end--;
                }
                if(abs(curr_sum - target)<abs(sum-target)){
                    
                    sum = curr_sum;
                    
                }
                
                
            }
            
            
        }
        
        return sum;
    }
};