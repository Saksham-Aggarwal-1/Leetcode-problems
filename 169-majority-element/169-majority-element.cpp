class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0], count = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == ele)
            {
                count++;
            }
            else
            {
                if(count > 1)
                    count --;
                else
                {
                    ele = nums[i];
                }
            }
        }
        
        return ele;
    }
};