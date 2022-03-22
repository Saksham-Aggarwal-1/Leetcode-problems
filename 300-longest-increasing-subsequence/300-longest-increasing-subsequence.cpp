class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp;
        
        
        for(int i:nums)
        {
            if(dp.size() == 0)
                dp.push_back(i);
            else if(i > dp.back())
                dp.push_back(i);
            else
            {
                int idx=0;
                while(dp[idx]<i)
                    idx++;
                dp[idx] = i;
            }
        }
        
        return dp.size();
    }
};