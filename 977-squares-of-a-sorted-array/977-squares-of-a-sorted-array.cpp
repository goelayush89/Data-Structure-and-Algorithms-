class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0;
        int j = nums.size()-1;
        vector<int>ans(j+1);
        int ind=j;
        while(i<=j){
            
            
            if(abs(nums[i])>=abs(nums[j])){
                ans[ind]=nums[i]*nums[i];
                i++;
                
        }else{
                ans[ind]=nums[j]*nums[j];
                j--;
            }
            
            
            
            ind--;
    }
        
        return ans;}
};