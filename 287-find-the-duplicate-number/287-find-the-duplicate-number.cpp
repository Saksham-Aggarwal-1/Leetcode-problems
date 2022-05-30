class Solution {
public:
    void printarr(vector<int> nums)
    {
        for(int i: nums)
            cout<<i<<" ";
        cout<<"\n";
    }
    
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])-1] < 0)
                return abs(nums[i]);
            else
                nums[abs(nums[i])-1] *= -1;
            //printarr(nums);
        }
        
        return 0;
    }
};