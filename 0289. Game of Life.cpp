class Solution
{
    int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        auto next = vector<vector<int>>(board.size(), vector<int>(board[0].size(), 0));
        
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                int cnt = 0;
                
                for (int k = 0; k < 8; ++k)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    
                    if (x >= 0 and x < board.size()
                       and y >= 0 and y < board[i].size()
                       and board[x][y])
                    {
                        ++cnt;
                    }
                }
                
                if (board[i][j] and (cnt == 3 or cnt == 2))
                {
                    next[i][j] = 1;
                }
                
                if (not board[i][j] and cnt == 3)
                {
                    next[i][j] = 1;
                }
            }
        }
        
        board = next;
    }
};