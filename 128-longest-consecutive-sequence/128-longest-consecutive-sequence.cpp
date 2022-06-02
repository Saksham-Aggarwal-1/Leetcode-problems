class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int ans = 0, temp=1;
        for(int i: s)
        {
            if(s.count(i-1))
                continue;
            int curr = i+1;
            while(s.count(curr)){
                temp++;
                curr++;
            }
            ans = max(ans, temp);
            temp=1;
        }
        
        return ans;
    }
};