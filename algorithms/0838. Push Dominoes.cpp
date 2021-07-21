class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.size();
        
        vector<int> lr(n);
        
        for (int i = 0; i < n; ++i)
        {
            if (dominoes[i] == 'R')
            {
                lr[i] = n;
            }
            else if (dominoes[i] == 'L')
            {
                lr[i] = 0;
            }
            else if (i > 0 and lr[i - 1] > 0)
            {
                lr[i] = lr[i - 1] - 1;
            }
        }
        
        vector<int> rl(n);
        
        for (int i = n - 1; i >= 0; --i)
        {
            if (dominoes[i] == 'L')
            {
                rl[i] = -n;
            }
            else if (dominoes[i] == 'R')
            {
                rl[i] = 0;
            }
            else if (i < n - 1 and rl[i + 1] < 0)
            {
                rl[i] = rl[i + 1] + 1;
            }
        }
        
        vector<int> res(n);
        
        for (int i = 0; i < n; ++i)
        {
            res[i] = lr[i] + rl[i];
        }
        
        string ans = "";
        
        for (int item : res)
        {
            if (item > 0)
            {
                ans += "R";
            }
            else if (item < 0)
            {
                ans += "L";
            }
            else
            {
                ans += ".";
            }
        }
        
        return ans;
    }
};