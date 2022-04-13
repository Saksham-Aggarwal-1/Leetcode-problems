class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0, mod = pow(10,9)+7;
        int odd=0, even=0;
        int sum=0;
        for(int i: arr)
        {
            sum += i;
            if(sum%2 == 0)
            {
                ans = (ans+odd)%mod;
                even++;
            }
            else
            {
                ans = (ans+even+1)%mod;
                odd++;
            }
        }
        
        return ans;
    }
};