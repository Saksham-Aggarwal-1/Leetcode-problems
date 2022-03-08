class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3)
            return ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i>0 && nums[i] == nums[i-1])
                continue;
            int low=i+1, high=nums.size()-1;
            while(low < high)
            {
                int temp = nums[i] + nums[low] + nums[high];
                if(temp == 0)
                {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    while(low<high && nums[low+1]==nums[low])
                        low++;
                    while(low<high && nums[high-1]==nums[high])
                        high--;
                    low++;
                    high--;
                }
                else if(temp < 0)
                    low++;
                else 
                    high--;
            }
        }
        
        return ans;
    }
};