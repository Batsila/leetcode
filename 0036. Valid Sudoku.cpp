class Solution
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        return check_rows(board) 
            and check_columns(board)
            and check_sectors(board);
    }
    
    bool check_rows(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; ++i)
        {
            unordered_set<int> s;
            
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    if (s.find(board[i][j]) != s.end())
                    {
                        return false;
                    }
                    
                    s.insert(board[i][j]);
                }
            }
        }
        
        return true;
    }
    
    bool check_columns(vector<vector<char>>& board)
    {
        for (int j = 0; j < 9; ++j)
        {
            unordered_set<int> s;
            
            for (int i = 0; i < 9; ++i)
            {
                if (board[i][j] != '.')
                {
                    if (s.find(board[i][j]) != s.end())
                    {
                        return false;
                    }
                    
                    s.insert(board[i][j]);
                }
            }
        }
        
        return true;
    }
    
    bool check_sectors(vector<vector<char>>& board)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                unordered_set<int> s;
                
                for (int si = 0; si < 3; ++si)
                {
                    for (int sj = 0; sj < 3; ++sj)
                    {
                        if (board[i * 3 + si][j * 3 + sj] != '.')
                        {
                            if (s.find(board[i * 3 + si][j * 3 + sj]) != s.end())
                            {
                                return false;
                            }
                    
                            s.insert(board[i * 3 + si][j * 3 + sj]);
                        }
                    }
                }
            }
        }
        
        return true;
    }
};