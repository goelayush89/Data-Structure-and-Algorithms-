class Solution {
public:
    int pivotIndex(vector<int>& nums) {
     int n = nums.size();
        vector<int>pref(n,0);
        int sum=0; 
        for (int x: nums) sum += x;
        pref[0] =nums[0];
        for(int i=1;i<nums.size();i++){
         pref[i] = pref[i-1]+nums[i];
        }
        
        
        
        
        if( sum-nums[0]==0) return 0;
        
        
        for(int i=1;i<n;i++){
            
           
            
            if(pref[i-1]==sum-pref[i-1]-nums[i]) return i;
            
        }
        
        return -1;
    }
};