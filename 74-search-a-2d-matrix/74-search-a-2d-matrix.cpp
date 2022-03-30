class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> temp;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                temp.push_back(matrix[i][j]);
            }
        }
        
        for(int i: temp)
            cout<<i<<" ";
        
        int l = 0, h = temp.size()-1;
        while(l<=h)
        {
            int m = l+(h-l)/2;
            if(temp[m] == target)
                return true;
            else if(temp[m] < target)
                l=m+1;
            else
                h=m-1;
        }
        
        return false;
    }
};