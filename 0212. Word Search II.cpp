class Solution
{
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, -1, 0, 1 };
    vector<vector<char>> b;
    
    unordered_set<string> w;
    unordered_set<string> ans;
    
    int max_l = 0; 
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        b = board;
        
        for (string word : words)
        {
            w.insert(word);
            
            max_l = max(max_l, (int)word.size());
        }
        
        for (int i = 0; i < b.size(); ++i)
        {
            for (int j = 0; j < b[0].size(); ++j)
            {  
                string c = string(1, b[i][j]);
                
                dfs(i, j, c);
            }
        }
        
        return vector<string>(ans.begin(), ans.end());
    }
    
    void dfs(int i, int j, string c)
    {     
        if (w.find(c) != w.end())
        {
            ans.insert(c);
        }
        
        char t = b[i][j];
        b[i][j] = '-';
        
        if (c.size() < max_l and ans.size() < w.size())
        {
            for (int k = 0; k < 4; ++k)
            {
                int x = i + dx[k];
                int y = j + dy[k];
            
                if (x >= 0 and x < b.size() and y >= 0 and y < b[0].size() and b[x][y] != '-')
                {
                    dfs(x, y, c + b[x][y]);
                }
            }
        }
        
        b[i][j] = t;
    }
};