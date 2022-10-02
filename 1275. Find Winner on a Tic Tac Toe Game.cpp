class Solution
{
public:
    string tictactoe(vector<vector<int>>& moves)
    {
        vector<vector<string>> b(3, vector<string>(3, ""));
        
        bool is_x = true;
        
        for (auto move : moves)
        {
            b[move[0]][move[1]] = is_x ? "A" : "B";
            
            is_x = not is_x;
        }
        
        for (int i = 0; i < 3; ++i)
        {
            if (b[i][0] != "" and b[i][0] == b[i][1] and b[i][1] == b[i][2])
            {
                return b[i][0];
            }
            
            if (b[0][i] != "" and b[0][i] == b[1][i] and b[1][i] == b[2][i])
            {
                return b[0][i];
            }
        }
        
        if (b[1][1] != "" and b[0][0] == b[1][1] and b[1][1] == b[2][2])
        {
            return b[1][1];
        }
        
        if (b[1][1] != "" and b[0][2] == b[1][1] and b[1][1] == b[2][0])
        {
            return b[1][1];
        }
        
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};