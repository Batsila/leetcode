class Solution
{
    unordered_set<int> columns;
    unordered_set<int> diagonals_1;
    unordered_set<int> diagonals_2;
    int n;
    vector<vector<string>> ans;
    vector<string> board;

public:
    vector<vector<string>> solveNQueens(int n)
    {
        this->n = n;
        
        board = vector<string>(n, string(n, '.'));
        
        dfs(0);
        
        return ans;
    }
    
    void dfs(int row)
    {
        if (row == n)
        {
            ans.push_back(board);
        }
        else
        {
            for (int col = 0; col < n; ++col)
            {
                if (columns.find(col) == columns.end()
                   and diagonals_1.find(row - col) == diagonals_1.end()
                   and diagonals_2.find(col + row) == diagonals_2.end())
                {
                    board[row][col] = 'Q';
                    columns.insert(col);
                    diagonals_1.insert(row - col);
                    diagonals_2.insert(col + row);
                    
                    dfs(row + 1);
                    
                    board[row][col] = '.';
                    columns.erase(col);
                    diagonals_1.erase(row - col);
                    diagonals_2.erase(col + row);
                }
            }
        }
    }
};