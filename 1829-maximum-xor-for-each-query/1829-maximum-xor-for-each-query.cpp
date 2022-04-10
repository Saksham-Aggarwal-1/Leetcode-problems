class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        
        int xor1 = 0;
        for(int i: nums)
            xor1 ^= i;
        
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            ans.push_back((1 << maximumBit)-1-xor1);
            xor1 ^= nums[n-i-1];
        }
        
        return ans;
    }
};