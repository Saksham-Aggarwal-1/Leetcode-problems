class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxnum = INT_MIN, maxidx = -1, minnum = INT_MAX, minidx = -1, n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i] > maxnum)
            {
                maxnum = nums[i];
                maxidx = i;
            }
            if(nums[i] < minnum)
            {
                minnum = nums[i];
                minidx = i;
            }
        }
        int a = min(maxidx, minidx), b = max(maxidx, minidx);
        return min(a+1+n-b, min(b+1, n-a));
    }
};