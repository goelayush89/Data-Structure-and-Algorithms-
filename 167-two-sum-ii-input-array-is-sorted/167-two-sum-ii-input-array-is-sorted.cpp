class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int n =numbers.size()-1;
        vector<int>ans;
        while(i<n){
            if(numbers[i]+numbers[n]==target )
            {
                ans.push_back(i+1);
                 ans.push_back(n+1);
           return ans;
            
            
            }else if (numbers[i]+numbers[n]<target){
            
            i++;
        }else{
     n--;
        }
    }return {-1,-1};
    }


};

