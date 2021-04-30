class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) 
    {
        set<int> s;
        
        for (int i = 0; i < (x == 1 ? 1 : log(bound) / log(x)); ++i)
        {
            for (int j = 0; j < (y == 1 ? 1 : log(bound) / log(y)); ++j)
            {
                int pi = pow(x, i) + pow(y, j);
                
                if (pi <= bound)
                {
                    s.insert(pi);
                }
            }
        }
        
        return vector<int>(s.begin(), s.end());
    }
};