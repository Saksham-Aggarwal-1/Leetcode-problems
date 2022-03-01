class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int> &temp, vector<vector<int>> graph, int n)
    {
        temp.push_back(n);
        if(n == graph.size()-1)
        {
            ans.push_back(temp);
            //return;
        }
        
        for(auto it: graph[n])
        {
            dfs(ans, temp, graph, it);
        }
        
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(ans, temp, graph, 0);
        
        return ans;
    }
};