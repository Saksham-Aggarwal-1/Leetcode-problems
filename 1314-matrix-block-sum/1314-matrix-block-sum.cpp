class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> rangesum(n+1, vector<int>(m+1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                rangesum[i+1][j+1] = rangesum[i+1][j]+rangesum[i][j+1]-rangesum[i][j]+mat[i][j];
            }
        }
        
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int r1=max(0, i-k), r2=min(n, i+k+1), c1=max(0, j-k), c2=min(m, j+k+1);
                ans[i][j] = rangesum[r2][c2]-rangesum[r2][c1]-rangesum[r1][c2]+rangesum[r1][c1];
            }
        }
        
        return ans;
    }
};