class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int ma = nums[i], mi = nums[i];
            for (int j = i; j < nums.size(); j++) {
                ma = max(ma, nums[j]);
                mi = min(mi, nums[j]);
                ans += ma - mi;
            }
        }
        return ans;
    }
};