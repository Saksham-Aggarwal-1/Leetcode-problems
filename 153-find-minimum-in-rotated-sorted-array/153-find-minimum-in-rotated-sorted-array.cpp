class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size()-1;
        int mid=0;
        while(l<h)
        {
            if(h-l == 1)
                return min(nums[l], nums[h]);
            mid = l+(h-l)/2;
            if(nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1])
                return nums[mid];
            else if(nums[mid] < nums[l])
                h = mid-1;
            else if(nums[mid] > nums[h])
                l = mid+1;
            else
                return nums[l];
        }
        return nums[l];
    }
};