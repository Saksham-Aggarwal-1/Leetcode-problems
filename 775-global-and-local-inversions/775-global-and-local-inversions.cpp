class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        if(nums.size() < 3)
            return true;
        int maxtillnow = -1;
        for(int i=0;i<nums.size()-2;i++)
        {
            maxtillnow = max(maxtillnow, nums[i]);
            if(maxtillnow > nums[i+2])
                return false;
        }
        
        return true;
    }
};