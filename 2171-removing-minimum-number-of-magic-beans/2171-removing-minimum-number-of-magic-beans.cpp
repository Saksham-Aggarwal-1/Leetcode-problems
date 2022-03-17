class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n=beans.size();
        sort(beans.begin(), beans.end());
        long long ans=LLONG_MAX;
        long long sum=0;
        for(int x: beans)
        {
            sum+=x;
        }
        for(int i=0;i<n;i++)
        {
            ans=min(ans, (long long)sum-(long long)(n-i)*(long long)beans[i]);
        }
        
        return ans;
    }
};