class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {        
        unordered_set<int> seenAmount;
        queue<int> fillValues;
        fillValues.push(0);       
        
        int levels = 0;
        while(!fillValues.empty()){            
            int size = fillValues.size();
            for(int i = 0; i < size; i++){
                int currAmount = fillValues.front(); fillValues.pop();
                
                if(currAmount == amount) return levels;
                
                for(int &coin : coins){
                    if(coin <= amount){
                        int newAmount = currAmount + coin;
                        
                        if(newAmount <= amount && seenAmount.find(newAmount) == seenAmount.end()){
                            seenAmount.insert(newAmount);
                            fillValues.push(newAmount);
                        }
                    }
                }
            }
            
            levels++;
        }
        
        return -1;
    }
};