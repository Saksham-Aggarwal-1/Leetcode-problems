class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if(a[0]<b[0] || (a[0] == b[0] && a[1] < b[1]))
            return true;
        return false;
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), cmp);
        
        vector<int> dp(n+1, 1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[j][1] < pairs[i][0])
                    dp[i]=max(dp[i], dp[j]+1);
            }
        }
        
        int ans=INT_MIN;
        for(int x: dp)
            ans = max(ans, x);
        return ans;
    }
};