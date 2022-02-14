class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int& temp)
    {
        int n = grid1.size(), m = grid1[0].size();
        if(i > n-1 || i < 0 || j > m-1 || j < 0)
            return;
        if(grid2[i][j] == 1 && grid1[i][j] == 0)
        {
            temp = false;
            return;
        }
        if(grid2[i][j] == 0)
            return;
        grid2[i][j] = 0;
        dfs(grid1, grid2, i, j+1, temp);
        dfs(grid1, grid2, i, j-1, temp);
        dfs(grid1, grid2, i+1, j, temp);
        dfs(grid1, grid2, i-1, j, temp);
        return;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        int n = grid2.size();
        int m = grid2[0].size();
        
        for(int i = 0 ; i < n ; i ++)
        {
            for(int j = 0 ; j < m ; j ++)
            {
                if(grid2[i][j] == 1)
                {
                    int temp = true;
                    dfs(grid1, grid2, i, j, temp);
                    ans += temp;
                }
            }
        }
        
        return ans;
    }
};