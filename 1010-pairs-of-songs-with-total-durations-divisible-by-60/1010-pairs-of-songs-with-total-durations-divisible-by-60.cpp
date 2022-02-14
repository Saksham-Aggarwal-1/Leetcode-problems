class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        
        for(int i = 0; i < time.size(); i++)
        {
            time[i] = time[i]%60;
        }
        
        int mp[60] = {0};
        
        for(int i: time)
            mp[i]++;
        
        for(int i=1;i<30;i++)
        {
            ans += mp[i]*mp[60-i];
        }
        
        if(mp[0]%2 == 0)
            ans+=(mp[0]/2)*(mp[0]-1);
        else
            ans+=(mp[0])*((mp[0]-1)/2);
        
        if(mp[30]%2 == 0)
            ans+=(mp[30]/2)*(mp[30]-1);
        else
            ans+=(mp[30])*((mp[30]-1)/2);
        return ans;
    }
};