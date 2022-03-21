class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxlen=0, ans=0;
        vector<int> dp(n+1, 1);
        vector<int> count(n+1, 1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(dp[i] == dp[j]+1)
                        count[i] += count[j];
                    else if(dp[i] < dp[j]+1)
                    {
                        dp[i]= dp[j]+1;
                        count[i] = count[j];
                    }
                }
            }
            if(maxlen == dp[i])
                ans += count[i];
            if(maxlen < dp[i]){
                maxlen = dp[i];
                ans = count[i];
            }
        }
        
        return ans;
    }
};