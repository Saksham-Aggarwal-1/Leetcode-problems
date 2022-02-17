class Solution {
public:
    int solve(int n, vector<int>& dp, string s)
    {
        if(dp[n] != -1)
            return dp[n];
        
        if(s[n] == '0')
            return dp[n] = 0;
        
        int res = solve(n+1, dp, s);
        
        if((n<s.length()-1) && (s[n] == '1' || (s[n] == '2' && s[n+1] < '7')))
            res += solve(n+2, dp, s);
        
        return dp[n] = res;
    }
    
    int numDecodings(string s) {
        
        int n = s.length();
        
        if(s.length() == 0)
            return 0;
        
        vector<int>dp(n+1, -1);
        dp[n] = 1;
        
        return solve(0, dp, s);
    }
};