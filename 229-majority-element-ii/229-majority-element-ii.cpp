class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mp;
        for(int i: nums)
            mp[i]++;
        int n = nums.size();
        vector<int> ans;
        for(auto it: mp)
        {
            if(it.second > n/3)
                ans.push_back(it.first);
        }
        
        return ans;
    }
};