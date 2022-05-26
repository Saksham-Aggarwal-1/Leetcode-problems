class Solution {
public:
    
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        for(int x: tasks)
        {
            mp[x]++;
        }
        int maxnum = INT_MIN;
        for(auto x: mp)
        {
            if(x.second == 1)
                return -1;
            maxnum = max(maxnum, x.second);
        }
        
        vector<int> dp(maxnum+1);
        dp[0] = 0;
        dp[1] = -1;
        
        for(int i=2;i<maxnum+1;i++)
        {
            if(i == 2)
                dp[i] = 1;
            else if(i == 3)
                dp[i] = 1;
            else if(i == 4)
                dp[i] = 2;
            else
                dp[i] = min(dp[i-2], dp[i-3])+1;
        }
        
        int ans = 0;
        for(auto x: mp)
            ans += dp[x.second];
        
        return ans;
    }
};