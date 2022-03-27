class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if(a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]))
            return true;
        return false;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> temp;
        int count=0;
        for(int i=0;i<mat.size();i++)
        {
            count=0;
            for(int j=0;j<mat[0].size();j++)
            {
                count += mat[i][j];
            }
            temp.push_back({i, count});
        }
        
        sort(temp.begin(), temp.end(), cmp);
        
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(temp[i][0]);
        }
        
        return ans;
    }
};