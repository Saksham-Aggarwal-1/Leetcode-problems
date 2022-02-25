class Solution {
public:
    int calc(vector<vector<int>> board, int i, int j)
    {
        int n = board.size(), m = board[0].size();
        int ans = 0;
        
        if(i>0) {
		ans += board[i-1][j];
	    }
        if(i<n-1) {
		ans += board[i+1][j];
	    }
        if(j<m-1) {
		ans += board[i][j+1];
	    }
        if(j>0) {
		ans += board[i][j-1];
	    }
        

        if(i>0 && j>0) {
            ans += board[i-1][j-1];
        }
        
        if(i>0 && j<m-1) {
            ans += board[i-1][j+1];
        }
        
        if(i<n-1 && j>0) {
            ans += board[i+1][j-1];
        }
        
        if(i<n-1 && j<m-1) {
            ans += board[i+1][j+1];
        }
        
        return ans;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<vector<int>> dead, live;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                int temp = calc(board, i, j);
                if(board[i][j] == 1)
                {
                    if(temp<2 || temp>3)
                        dead.push_back({i,j});
                }
                else
                {
                    if(temp == 3)
                        live.push_back({i,j});
                }
            }
        }
        
        for(auto v:dead)
        {
            board[v[0]][v[1]] = 0;
        }
        for(auto v:live)
        {
            board[v[0]][v[1]] = 1;
        }
        return;
    }
};