class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<vector<int>> temp(n, vector<int>(m, 0));
        for(int i=0;i<m;i++)
        {
            int curr=0, j=0;
            while(j<n)
            {
                if(matrix[j][i] == 1)
                {
                    curr++;
                    temp[j][i] = curr;
                }
                else
                {
                    curr=0;
                    temp[j][i] = curr;
                }
                j++;
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            sort(temp[i].begin(), temp[i].end(), greater<int>());
            int curr=temp[i][0];
            ans = max(ans, curr);
            for(int j=1;j<m;j++)
            {
                curr=(temp[i][j])*(j+1);
                ans=max(ans, curr);
            }
        }
        
        return ans;
    }
};