// Bit Manipulation

bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        if(sum % 2 != 0) return false;
        int halfSum = sum/2;
        bitset<10000> dp(1);
        for(int i = 0; i < nums.size(); i++){
            dp = dp | dp << nums[i];
        }
        return dp[halfSum];
        
        
    }
    
//      DP
    
    bool canPartition(vector<int>& nums) {
        int target = accumulate(begin(nums),end(nums),0);
        
        
        if (target % 2) {
            return false;
        }
        target /= 2;
        
        unordered_set<int> dp;
        dp.insert(0);
        
        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> dpNext;
            for (auto it = dp.begin(); it != dp.end(); it++) {
                if (*it + nums[i] == target) {
                    return true;
                }
                dpNext.insert(*it + nums[i]);
                dpNext.insert(*it);
            }
            dp = dpNext;
        }
        
        return false;
    }
