class Solution {
public:
//     int total;
    
//     int helper(vector<int>nums, int target, int i, int sum, vector<vector<int>> dp)
//     {
//         if(i == nums.size())
//         {
//             if(sum == target)
//                 return 1;
//             else
//                 return 0;
//         }
//         if(dp[i][sum+total] != INT_MIN)
//             return dp[i][sum+total];
//         return dp[i][sum+total] = helper(nums, target, i+1, sum+nums[i], dp) + helper(nums, target, i+1, sum-nums[i], dp);
        
//     }
    
    int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size(), sum = 0;
//         for(int i: nums)
//             sum += i;
//         total=sum;
        
//         vector<vector<int>> dp(n+1, vector<int>(2*sum+1, INT_MIN));
//         return helper(nums, target, 0, 0, dp);
        int total = 0;
        for(int i: nums)
            total += i;
        vector<vector<int>> dp(nums.size(), vector<int>(2*total + 1));
        dp[0][nums[0] + total] = 1;
        dp[0][-nums[0] + total] += 1;
        
        for(int i=1; i<nums.size(); i++)
        {
            for(int sum = -total; sum <= total; sum++)
            {
                if(dp[i-1][sum+total] > 0)
                {
                    dp[i][sum+nums[i]+total] += dp[i-1][sum+total];
                    dp[i][sum-nums[i]+total] += dp[i-1][sum+total];
                }
            }
        }
        
        if(abs(target)>total)
            return 0;
        else
            return dp[nums.size()-1][target+total];
        
    }
};