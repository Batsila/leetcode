class Solution 
{
public:
    vector<int> movesToStamp(string stamp, string target) 
    {
        vector<int> ans;
        
        bool ind = true;
        
        while (ind)
        {
            ind = false;
            
            for (int i = 0; i < target.size() - stamp.size() + 1; ++i)
            {
                int s = 0;
                int q = 0;
                
                for (int j = 0; j < stamp.size(); ++j)
                {
                    if (target[i + j] == stamp[j])
                    {
                        ++s;
                    }
                    else if (target[i + j] == '?')
                    {
                        ++q;
                    }
                    else
                    {
                        break;
                    }
                }

                if (s + q == stamp.size() && s)
                {
                    ans.push_back(i);
                    
                    for (int j = 0; j < stamp.size(); ++j)
                    {
                        target[i + j] = '?';
                    }
                    
                    ind = true;
                }
            }
        }
        
        for (int i = 0; i < target.size(); ++i)
        {
            if (target[i] != '?')
            {
                return vector<int>();
            }
        }
        
        reverse(ans.begin(), ans.end());
            
        return ans;
    }
};