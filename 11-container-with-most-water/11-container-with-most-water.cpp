class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int low =0;
        int high = height.size()-1;
        int maxA =0;
        while(low <high){
            
          maxA = max(maxA,(high-low)*min(height[low],height[high]));
            if(height[low]<height[high]){
             low++;
            }else{
                high--;
            }
            
                
                
            }
        
    
    return maxA;
    }
};