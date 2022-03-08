class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[nums.size()-1];
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int lo = i+1, hi = nums.size()-1;
            
            while(lo<hi)
            {
                int temp = nums[i]+nums[lo]+nums[hi];
                if(abs(temp-target)<abs(ans-target))
                    ans=temp;
                if(temp == target)
                    return temp;
                else if(temp>target)
                {
                    hi--;
                }
                else
                {
                    lo++;
                }   
            }
        }
        
        return ans;
    }
};