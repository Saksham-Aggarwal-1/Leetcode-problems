class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int i=0;i<numRows;i++)
        {
            if(i == 0)
            {
                ans.push_back({1});
            }
            else
            {
                vector<int> temp = ans.back();
                vector<int> newTemp;
                newTemp.push_back(1);
                for(int i=0;i<temp.size()-1;i++)
                {
                    newTemp.push_back(temp[i]+temp[i+1]);
                }
                newTemp.push_back(1);
                ans.push_back(newTemp);
            }
        }
        
        return ans;
    }
};