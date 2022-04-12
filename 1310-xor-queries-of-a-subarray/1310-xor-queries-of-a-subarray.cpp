class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        
        vector<int> prefix;
        
        prefix.push_back(arr[0]);
        for(int i=1;i<arr.size();i++)
            prefix.push_back( arr[i] ^ prefix.back() );
        
        for(auto v: queries)
        {
            if(v[0] == 0)
                ans.push_back(prefix[v[1]]);
            else
                ans.push_back(prefix[v[1]]^prefix[v[0]-1]);
        }
        
        return ans;
    }
};