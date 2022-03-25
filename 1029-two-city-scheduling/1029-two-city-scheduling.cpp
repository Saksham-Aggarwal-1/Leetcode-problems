class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans = 0;
        vector<int> temp;
        for(auto x: costs)
        {
            ans += x[0];
            temp.push_back(x[1]-x[0]);
        }
        sort(temp.begin(), temp.end());
        int n=costs.size();
        for(int i=0;i<n/2;i++)
            ans += temp[i];
        return ans;
    }
};