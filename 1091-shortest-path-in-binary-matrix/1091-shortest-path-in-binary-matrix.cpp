class Solution {
public:
    int bfs(vector<vector<int>> grid, queue<pair<int, int>> q)
    {
        vector<vector<int>> visited(grid.size(), vector<int>(grid.size(), 0));
        //cout<<"entering bfs function\n";
        int ans = 1;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                pair<int,int> p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                //cout<<x<<" and "<<y<<" popped\n";
                
                if(visited[x][y] == 1)
                    continue;
                
                if(x == grid.size()-1 && y == grid.size()-1){
                    //cout<<ans <<" returned\n";
                    return ans;
                }
                
                if(x>0 && grid[x-1][y] == 0 && visited[x-1][y] == 0){
                    cout<<x-1<<" and "<<y<<" pushed\n";   
                    q.push({x-1, y});
                }
                if(y>0 && grid[x][y-1] == 0 && visited[x][y-1] == 0){
                    cout<<x<<" and "<<y-1<<" pushed\n";
                    q.push({x, y-1});
                }
                    
                if(x<grid.size()-1 && grid[x+1][y] == 0 && visited[x+1][y] == 0){
                    cout<<x+1<<" and "<<y<<" pushed\n";
                    q.push({x+1, y});
                }
                    
                if(y<grid.size()-1 && grid[x][y+1] == 0 && visited[x][y+1] == 0){
                    cout<<x<<" and "<<y+1<<" pushed\n";
                    q.push({x, y+1});
                }
                    
                
                if(x>0 && y>0 && grid[x-1][y-1] == 0 && visited[x-1][y-1] == 0){
                    cout<<x-1<<" and "<<y-1<<" pushed\n";
                    q.push({x-1, y-1});
                }
                    
                if(x>0 && y<grid.size()-1 && grid[x-1][y+1] == 0 && visited[x-1][y+1] == 0){
                    cout<<x-1<<" and "<<y+1<<" pushed\n";
                    q.push({x-1, y+1});
                }
                    
                if(x<grid.size()-1 && y>0 && grid[x+1][y-1] == 0 && visited[x+1][y-1] == 0){
                    cout<<x+1<<" and "<<y-1<<" pushed\n";
                    q.push({x+1, y-1});
                }
                    
                if(x<grid.size()-1 && y<grid.size()-1 && grid[x+1][y+1] == 0 && visited[x+1][y+1] == 0){
                    cout<<x+1<<" and "<<y+1<<" pushed\n";
                    q.push({x+1, y+1});
                }
                
                visited[x][y] = 1;
                
            }
            ans++;
        }
        
        return -1;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)
            return -1;
        queue<pair<int, int>> q;
        q.push({0,0});
        return bfs(grid, q);
    }
};