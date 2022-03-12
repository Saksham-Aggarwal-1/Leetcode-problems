class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long ans = (long long)k * (k + 1) / 2;
        set<int> s(begin(nums), end(nums)); 
        for (int n : s){
            if (n <= k)
            {
                ans -= n;
                ans += (k+1);
                k++;
            }
        }
        return ans;
    }
};