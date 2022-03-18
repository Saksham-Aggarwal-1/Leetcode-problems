class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        long long int temp1=horizontalCuts[0];
        int n=horizontalCuts.size();
        for(int i=1;i<n;i++)
        {
            temp1=max(temp1,(long long int) horizontalCuts[i]-horizontalCuts[i-1]);
        }
        temp1=max(temp1,(long long int) h-horizontalCuts[n-1]);
        
        long long int temp2=verticalCuts[0];
        n=verticalCuts.size();
        for(int i=1;i<n;i++)
        {
            temp2=max(temp2,(long long int) verticalCuts[i]-verticalCuts[i-1]);
        }
        temp2=max(temp2,(long long int) w-verticalCuts[n-1]);
        
        long long int mod = 1000000007;
        return (int)(temp1%mod*temp2%mod);
    }
};