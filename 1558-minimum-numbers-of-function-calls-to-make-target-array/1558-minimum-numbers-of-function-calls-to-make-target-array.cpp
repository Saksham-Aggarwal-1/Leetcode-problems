class Solution {
public:
    int minOperations(vector<int>& nums) {
        int maxLen = 1, ans=0;
        for(int i: nums)
        {
            int bits=0;
            while(i>0)
            {
                ans += i&1;
                bits++;
                i >>= 1;
            }
            maxLen = max(maxLen, bits);
        }
        return ans + maxLen-1;
    }
};