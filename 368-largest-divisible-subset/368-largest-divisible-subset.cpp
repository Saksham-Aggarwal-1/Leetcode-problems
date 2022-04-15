class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxint = INT_MIN, lastidx=0;
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n);
        for(int i=1;i<n;i++)
        {
            hash[i] = i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j] == 0 && dp[i]<dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
            }
            if(dp[i] > maxint) {
                maxint = dp[i];
                lastidx = i;
            }
        }
        
        vector<int> ans;
        ans.push_back(nums[lastidx]);
        while(hash[lastidx] != lastidx)
        {
            lastidx = hash[lastidx];
            ans.push_back(nums[lastidx]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};