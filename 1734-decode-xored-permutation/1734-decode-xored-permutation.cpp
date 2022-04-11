class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1, a = 0;
        for (int i = 0; i <= n; ++i) {
            a ^= i;
            if (i < n && i % 2 == 1) {
                a ^= encoded[i];
            }
        }
        vector<int> ans;
        ans.push_back(a);
        for(int i: encoded)
        {
            ans.push_back(ans.back()^i);
        }
        
        return ans;
    }
};