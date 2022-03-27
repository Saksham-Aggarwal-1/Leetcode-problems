class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& temp, int curr, vector<int> nums)
    {
        unordered_set<int> mp;
        if(temp.size() > 1)
            ans.push_back(temp);
        for(int i=curr; i<nums.size(); i++)
        {
            if((temp.size() == 0 || nums[i]>= temp.back()) && mp.find(nums[i]) == mp.end())
            {
                temp.push_back(nums[i]);
                backtrack(ans, temp, i+1, nums);
                temp.pop_back();
                mp.insert(nums[i]);
            }
        }
    }
        
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(ans, temp, 0, nums);
        return ans;
    }
};