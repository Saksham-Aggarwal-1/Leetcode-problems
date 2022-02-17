class Solution {
public:
    int nthUglyNumber(int n) {
        
        int dp[n+1];
        dp[1] = 1;
        int ptr2=1, ptr3=1, ptr5=1;
        for(int i=2; i<=n; i++)
        {
            dp[i] = min(2*dp[ptr2], min(3*dp[ptr3], 5*dp[ptr5]));
            if(dp[i] == 2*dp[ptr2])
                ptr2++;
            if(dp[i] == 3*dp[ptr3])
                ptr3++;
            if(dp[i] == 5*dp[ptr5])
                ptr5++;
        }
        
        return dp[n];
    }
};