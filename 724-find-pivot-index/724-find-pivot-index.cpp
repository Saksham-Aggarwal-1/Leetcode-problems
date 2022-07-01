class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i=nums.size()-1;
        int left_sum=0, right_sum = 0;
        while(i>0)
        {
            right_sum += nums[i];
            i--;
        }
        
        while(i < nums.size()-1)
        {
            if(left_sum == right_sum)
                return i;
            left_sum += nums[i];
            right_sum -= nums[i+1];
            i++;
        }
        
        if(left_sum == 0)
            return i;
        
        return -1;
    }
};