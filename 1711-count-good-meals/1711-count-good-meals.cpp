class Solution {
public:
    int mod = 1000000007;
    int countPairs(vector<int>& deliciousness) {
        long ans=0;
        map<int,int> mp;
        for(int x:deliciousness)
        {
            int power=1;
            for(int i=0;i<22;i++)
            {
                if(mp.find(power-x) != mp.end())
                {
                    ans += mp[power-x];
                    ans %= mod;
                }
                power *= 2;
            }
            mp[x]++;
        }
        
        return (int)ans;
    }
};