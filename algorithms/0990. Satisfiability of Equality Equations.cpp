class Solution
{
    int uf[26];
    
    int find(int x)
    {
        if (uf[x] != x)
        {
            uf[x] = find(uf[x]);
        }
        
        return uf[x];
    }
    
public:
    bool equationsPossible(vector<string>& equations)
    {
        for (int i = 0; i < 26; ++i)
        {
            uf[i] = i;
        }
        
        for (string equation : equations)
        {
            if (equation[1] == '=')
            {
                uf[find(equation[0] - 'a')] = find(equation[3] - 'a');
            }
        }
        
        for (string equation : equations)
        {
            if (equation[1] == '!'
               and find(equation[0] - 'a') == find(equation[3] - 'a'))
            {
                return false;
            }
        }
        
        return true;
    }
};