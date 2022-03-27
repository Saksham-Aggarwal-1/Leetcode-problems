class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if(a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]))
            return true;
        return false;
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int ans=0, n=properties.size();
        sort(properties.begin(), properties.end(), cmp);
        
        int maxn= INT_MIN;
        for(int i=n-1;i>-1;i--)
        {
            if(properties[i][1]<maxn)
            {
                ans++;
            }
            else
                maxn = properties[i][1];
        }
        
        return ans;
    }
};