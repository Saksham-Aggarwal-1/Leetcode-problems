class Solution {
public:
    bool solve(vector<vector<char>>& board, string word, int x, int y, int i)
    {
        if(i == word.length())
            return true;
        if(x<0 || y<0 || x >= board.size() || y>= board[0].size())
            return false;
        
        if(board[x][y] != word[i])
            return false;
        
        char temp = board[x][y];
        board[x][y] = '-';
        bool flag = (solve(board, word, x+1, y, i+1) || solve(board, word, x-1, y, i+1) || solve(board, word, x, y+1, i+1) || solve(board, word, x, y-1, i+1));
    
        board[x][y] = temp;
        return flag;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        // int n = word.length();
        // char char_array[n + 1];
        // strcpy(char_array, word.c_str());
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(solve(board, word, i, j, 0))
                    return true;
            }
        }
        
        return false;
    }
};