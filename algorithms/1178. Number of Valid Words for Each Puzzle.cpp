class Solution
{
    map<int, int> m; 
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
    {
        for (string word : words)
        {
            int bm = 0;
            
            for (char c : word)
            {
                bm |= 1 << (c - 'a');
            }
            
            ++m[bm];
        }
        
        vector<int> ans;
        
        for (string puzzle : puzzles)
        {
            int f = 1 << (puzzle[0] - 'a');
            
            int bm = 0;
            
            for (int i = 1; i < puzzle.size(); ++i)
            {
                bm |= 1 << (puzzle[i] - 'a');
            }
            
            int c = m[f];
            
            for (int sm = bm; sm; sm = (sm - 1) & bm)
            {
                c += m[sm | f];
            }
            
            ans.push_back(c);
        }
        
        return ans;
    }
};