class Solution {
public:
    void sortColors(vector<int>&arr) {
        int low=0;
        int mid =0;
        int high =arr.size()-1;
        
        while(mid<=high){
            
            if(arr[mid]==0){
                swap(arr[mid],arr[low]);
                mid++;
                low++;
            }
            
            else if (arr[mid]==1){
                mid++;
            }
            else if(arr[mid]==2){
                
                swap(arr[mid],arr[high]);
                high--;
                
            }
        }
        
        
    }
};