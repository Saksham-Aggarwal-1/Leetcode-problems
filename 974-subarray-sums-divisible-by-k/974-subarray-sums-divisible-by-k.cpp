class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int ans = 0, sum = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            int temp = sum%k;
            if(temp<0)
                temp += k;
            if(mp.find(temp) != mp.end())
            {
                ans += mp[temp];
                
            }
            
            mp[temp]++;
        }
     
        return ans;
    }
};